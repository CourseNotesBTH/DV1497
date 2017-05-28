//
//  HousingRegister.cpp
//  Uppgift A
//
//  Created by Marcus Lenander on 2017-03-20.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include <fstream>
#include <sstream>
#include "HousingRegister.hpp"

HousingRegister::HousingRegister()
{
    this->cap = 0;
    this->nrOfHousing = 0;
    this->housingArray = NULL;
}
HousingRegister::HousingRegister(int cap)
{
    this->cap = cap;
    this->nrOfHousing = 0;
    this->housingArray = new Housing*[this->cap];
}
HousingRegister::HousingRegister(const HousingRegister &origObj)
{
    this->cap = origObj.cap;
    this->nrOfHousing = origObj.nrOfHousing;
    this->housingArray = new Housing*[origObj.cap];
    
    for(int i = 0; i < origObj.nrOfHousing; i++)
        housingArray[i] = new Housing(*origObj.housingArray[i]);
}
HousingRegister& HousingRegister::operator=(const HousingRegister &origObj)
{
    if(this != &origObj)
    {
        for (int i = 0; i < this->nrOfHousing; i++)
            delete housingArray[i];
        delete[] this->housingArray;
        
        this->cap = origObj.cap;
        this->nrOfHousing = origObj.nrOfHousing;
        this->housingArray = new Housing*[origObj.cap];
        
        for(int i = 0; i < origObj.nrOfHousing; i++)
            housingArray[i] = new Housing(*origObj.housingArray[i]);
    }
    return *this;
}
HousingRegister::~HousingRegister()
{
    for (int i = 0; i < this->nrOfHousing; i++)
        delete housingArray[i];
    delete[] this->housingArray;
}
int HousingRegister::findId(string idNumber)
{
    int pos = -1;
    for(int i = 0; i < nrOfHousing; i++){
        if(nrOfHousing != 0){
            if(idNumber == housingArray[i]->getIdNumber())
                pos = i;
        }
    }
    return pos;
}
void HousingRegister::expand()
{
    Housing **temp = new Housing*[cap+1];
    for(int i=0; i<nrOfHousing; i++)
        temp[i] = housingArray[i];
    delete[] housingArray;
    housingArray = temp;
    cap++;
}
int HousingRegister::getNrOfHousings()const
{
    return this->nrOfHousing;
}
bool HousingRegister::addHousing(int rent, int area, int rooms, string idNumber, string address, string habitation)
{
    bool add = false;

        if(findId(idNumber) == -1)
        {
            if(nrOfHousing == cap)
                expand();
            
            housingArray[nrOfHousing] = new Housing(rent, area, rooms, idNumber, address, habitation);
            this->nrOfHousing++;
            add = true;
        }
    return add;
}

bool HousingRegister::showHousings(string aString[]) const
{
    bool index = false;

        for(int i=0; i<nrOfHousing; i++)
        {
            aString[i] = housingArray[i]->toString();
        }
        if(nrOfHousing > 0)
            index = true;
    
    return index;
}
bool HousingRegister::showRent(string aString[], int rent) const
{
    bool index = false;
    for (int i = 0; i < nrOfHousing; i++)
    {
        if(housingArray[i]->getRent() < rent)
        {
            aString[i] = housingArray[i]->toString();
            index = true;
        }
    }
    return index;
}
bool HousingRegister::showHabRooms(string aString[], string habitation, int rooms) const
{
    bool index = false;
    for(int i=0; i<nrOfHousing; i++)
    {
        if(housingArray[i]->getHabitation() == habitation)
        {
            if(housingArray[i]->getRooms() == rooms)
            {
                aString[i] = housingArray[i]->toString();
                index = true;
            }
        }
    }
    return index;
}
bool HousingRegister::deleteHousing(const string & idNumber)
{
    bool index = false;
    int pos = findId(idNumber);
    
    if(pos != -1)
    {
        delete this->housingArray[pos];
        this->nrOfHousing--;
        
        for(int j = pos; j < this->nrOfHousing; j++)
            housingArray[j] = housingArray[j+1];
        index = true;
    }
    return index;
}
bool HousingRegister::changeHousing(const string &idNumber, int rent, int area, int rooms, string address, string habitation)
{
    bool index = false;
    int nr = findId(idNumber);

    if(nr != -1)
    {
        index = true;
        housingArray[nr]->setRent(rent);
        housingArray[nr]->setArea(area);
        housingArray[nr]->setRooms(rooms);
        housingArray[nr]->setAddress(address);
        housingArray[nr]->setHabitation(habitation);
    }
    return index;
}
void HousingRegister::read(string filename)
{
    ifstream file(filename);
    string line;
    int index = 0;
    
    int rooms, rent, area;
    string idNumber, address, habitation;
    
    //Read line by line
    while (getline(file, line))
    {
        // First line of a housing object (3 lines per housing)
        if(index % 3 == 0){
            address = line;
        } else if(index % 3 == 1) {
            habitation = line;
        } else if(index % 3 == 2) {
            istringstream stream(line);
            stream >> idNumber >> rent >> rooms >> area;
            this->addHousing(rent, area, rooms, idNumber, address, habitation);
        }
        index++;
    }
    file.close();
}
void HousingRegister::save(string filename) const
{
    ofstream file(filename);
    /*
     int getRent() const;
     int getArea() const;
     int getRooms() const;
     string getIdNumber() const;
     string getAdress() const;
     string getHabitation() const
     */
    for(int i = 0; i < this->nrOfHousing; i++){
        file<<this->housingArray[i]->getAddress()<<endl;
        file<<this->housingArray[i]->getHabitation()<<endl;
        file<<this->housingArray[i]->getIdNumber()<<" "<<this->housingArray[i]->getRent()<< " "<<this->housingArray[i]->getRooms()<<" "<<this->housingArray[i]->getArea()<<endl;
    }
    file.close();
}