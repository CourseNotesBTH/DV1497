//
//  Housing.cpp
//  Inlämning A 2
//
//  Created by Alex Gustafsson on 2017-03-17.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include "Housing.hpp"
#include <sstream>

Housing::Housing(){
    this->id = -1;
    this->address = "N/A";
    this->rent = -1;
    this->type = "N/A";
    this->livingArea = -1;
    this->roomCount = -1;
}

Housing::Housing(const Housing& other){
    this->id = other.id;
    this->address = other.address;
    this->rent = other.rent;
    this->type = other.type;
    this->livingArea = other.livingArea;
    this->roomCount = other.roomCount;
}

Housing::Housing(int id, std::string address, float rent, std::string type, float livingArea, int roomCount){
    this->id = id;
    this->address = address;
    this->rent = rent;
    this->type = type;
    this->livingArea = livingArea;
    this->roomCount = roomCount;
}

bool Housing::operator == (const Housing& other) const{
    return this->id == other.id;
}

bool Housing::operator != (const Housing& other) const{
    return !(*this == other);
}

Housing& Housing::operator = (const Housing other) {
    if (this != &other)
    {
        this->id = other.id;
        this->address = other.address;
        this->rent = other.rent;
        this->type = other.type;
        this->livingArea = other.livingArea;
        this->roomCount = other.roomCount;
    }
    
    //convention
    return *this;
}

int Housing::getId() const{
    return this->id;
}

std::string Housing::toString() const{
    std::ostringstream stream;
    stream << "Housing: " << this->getId() << std::endl;
    stream << "Address: " << this->getAddress() << std::endl;
    stream << "Rent: " << this->getRent() << std::endl;
    stream << "Type: " << this->getType() << std::endl;
    stream << "Living area: " << this->getLivingArea() << std::endl;
    stream << "Room count: " << this->getRoomCount() << std:: endl;
    
    return stream.str();
}

std::string Housing::getAddress() const{
    return this->address;
}
void Housing::setAddress(std::string address){
    this->address = address;
}

float Housing::getRent() const{
    return this->rent;
}
void Housing::setRent(float rent){
    this->rent = rent;
}

std::string Housing::getType() const{
    return this->type;
}
void Housing::setType(std::string type){
    this->type = type;
}

int Housing::getLivingArea() const{
    return this->livingArea;
}
void Housing::setLivingArea(int livingArea){
    this->livingArea = livingArea;
}

int Housing::getRoomCount() const{
    return this->roomCount;
}
void Housing::setRoomCount(int roomCount){
    this->roomCount = roomCount;
}
