//
//  HousingRegister.cpp
//  Inlämning A 2
//
//  Created by Alex Gustafsson on 2017-03-17.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include "HousingRegister.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

Housing** housings;

int capacity;
int count;

HousingRegister::HousingRegister(){
    this->capacity = 0;
    this->count = 0;
}

HousingRegister::HousingRegister(int capacity){
    this->capacity = capacity;
    this->count = 0;
    
    this->housings = new Housing*[this->capacity];
}

HousingRegister::HousingRegister(const HousingRegister& other){
    this->capacity = other.capacity;
    this->count = other.count;
    
    this->housings = new Housing*[other.capacity];
    for(int i = 0; i < other.count; i++)
        this->housings[i] = new Housing(*other.housings[i]);
}

HousingRegister::~HousingRegister(){
    for(int i = 0; i < this->count; i++)
        delete this->housings[i];
    delete[] this->housings;
}

bool HousingRegister::operator == (const HousingRegister& other) const{
    bool matching = false;
    
    // Compare count and capacity, then compare each element (expected to be same order if equal)
    if(this->count == other.count && this->capacity == other.capacity){
        for(int i = 0; i < this->count; i++){
            if(this->housings[i] == other.housings[i]) {
                matching = true;
            } else {
                matching = false;
                break;
            }
        }
    }
    
    return matching;
}

bool HousingRegister::operator != (const HousingRegister& other) const{
    return !(*this == other);
}

HousingRegister& HousingRegister::operator = (const HousingRegister other){
    if(*this != other){
        for(int i = 0; i < this->count; i++)
            delete this->housings[i];
        delete[] this->housings;
        
        this->capacity = other.capacity;
        this->count = other.count;
        
        this->housings = new Housing*[other.capacity];
        for(int i = 0; i < other.count; i++)
            this->housings[i] = new Housing(*other.housings[i]);
    }
    
    //convention
    return *this;
}

bool HousingRegister::addHousing(int id, std::string address, float rent, std::string type, float livingArea, int roomCount){
    
    if(!this->housingExists(id)){
        Housing* housing = new Housing(id, address, rent, type, livingArea, roomCount);
    
        this->expand();
        this->housings[count] = housing;
        this->count++;
        
        return true;
    } else {
        return false;
    }
}

bool HousingRegister::changeHousing(int id, std::string address, float rent, std::string type, float livingArea, int roomCount){
    
    int index = -1;
    for(int i = 0; i < this->count; i++){
        if(this->housings[i]->getId() == id){
            index = (int)i;
            break;
        }
    }
    
    if(index != -1){
        this->housings[index]->setRent(rent);
        this->housings[index]->setType(type);
        this->housings[index]->setAddress(address);
        this->housings[index]->setRoomCount(roomCount);
        this->housings[index]->setLivingArea(livingArea);
        
        return true;
    } else {
        return false;
    }
}

bool HousingRegister::removeHousing(int id){
    bool found = false;
    int index = 0;
    
    for(int i = 0; i < this->count; i++){
        if(this->housings[i]->getId() == id){
            found = true;
            index = i;
            break;
        }
    }
    
    if(found){
        delete this->housings[index];
        this->housings[index] = nullptr;
        
        for(int i = index; i < this->count - 1; i++)
            this->housings[i] = this->housings[i + 1];
        this->count--;
        
        return true;
    } else {
        return false;
    }
}

int HousingRegister::getCount() const{
    return this->count;
}

bool HousingRegister::fetchStrings(std::string* array, int capacity) const{
    if(capacity >= this->capacity){
        for(int i = 0; i < this->count; i++)
            array[i] = this->housings[i]->toString();
        return true;
    } else {
        return false;
    }
}

bool HousingRegister::fetchStrings(std::string* array, int capacity, float maximumRent) const{
    if(capacity >= this->capacity){
        int count = 0;
        for(int i = 0; i < this->count; i++){
            if(this->housings[i]->getRent() < maximumRent){
                array[count] = this->housings[i]->toString();
                count++;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool HousingRegister::fetchStrings(std::string* array, int capacity, std::string type, int roomCount) const{
    if(capacity >= this->capacity){
        int count = 0;
        for(int i = 0; i < this->count; i++){
            if(this->housings[i]->getType() == type && this->housings[i]->getRoomCount() == roomCount){
                array[count] = this->housings[i]->toString();
                count++;
            }
        }
        return true;
    } else {
        return false;
    }
}

void HousingRegister::expand(){
    if(this->count + 1 > this->capacity){
        Housing** temp = new Housing*[this->capacity + 1];
        for(int i = 0; i < this->count; i++)
            temp[i] = this->housings[i];
        
        delete[] this->housings;
        
        this->housings = temp;
    }
}

void HousingRegister::save(std::string filename) const{
    std::ofstream file(filename);
    // Address
    // Type
    // id rent rooms area
    for(int i = 0; i < this->count; i++){
        file << this->housings[i]->getAddress() << std::endl;
        file << this->housings[i]->getType() << std::endl;
        file << this->housings[i]->getId() << " " << this->housings[i]->getRent() << " " << this->housings[i]->getRoomCount() << " " << this->housings[i]->getLivingArea() << std::endl;
    }
    file.close();
}

void HousingRegister::read(std::string filename){
    std::ifstream file(filename);
    std::string line;
    int lineNumber = 0;
    
    int id, roomCount;
    std::string address, type;
    float rent, livingArea;
    
    //Read line by line
    while (getline(file, line))
    {
        // First line of a housing object (3 lines per housing)
        if(lineNumber % 3 == 0){
            address = line;
        } else if(lineNumber % 3 == 1) {
            type = line;
        } else if(lineNumber % 3 == 2) {
            std::istringstream stream(line);
            stream >> id >> rent >> roomCount >> livingArea;
            this->addHousing(id, address, rent, type, livingArea, roomCount);
        }
        
        lineNumber++;
    }
    file.close();
}

bool HousingRegister::housingExists(int id) const{
    bool exists = false;
    for(int i = 0; i < this->count; i++){
        if(this->housings[i]->getId() == id){
            exists = true;
            break;
        }
    }
    
    return exists;
}
