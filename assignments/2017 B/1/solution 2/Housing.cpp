//
//  Housing.cpp
//  Uppgift A
//
//  Created by Marcus Lenander on 2017-03-20.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "Housing.hpp"

Housing::Housing()
{
    this->rent = 0;
    this->area = 0;
    this->rooms = 0;
    this->idNumber = "?";
    this->address = "?";
    this->habitation = "?";
}
Housing::Housing(int rent, int area, int rooms, string idNumber, string address, string habitation)
{
    this->rent = rent;
    this->area = area;
    this->rooms = rooms;
    this->idNumber = idNumber;
    this->address = address;
    this->habitation = habitation;
}
Housing::~Housing()
{
    
}
int Housing::getRent()const
{
    return this->rent;
}
int Housing::getArea() const
{
    return this->area;
}
int Housing::getRooms()const
{
    return this->rooms;
}
string Housing::getIdNumber()const
{
    return this->idNumber;
}
string Housing::getAddress() const
{
    return this->address;
}
string Housing::getHabitation()const
{
    return this->habitation;
}
void Housing::setRent(int rent)
{
    this->rent = rent;
}
void Housing::setArea(int area)
{
    this->area = area;
}
void Housing::setRooms(int rooms)
{
    this->rooms = rooms;
}
void Housing::setIdNumber(string idNumber)
{
    this->idNumber = idNumber;
}
void Housing::setAddress(string address)
{
    this->address = address;
}
void Housing::setHabitation(string habitation)
{
    this->habitation = habitation;
}
string Housing::toString()const
{
    return idNumber + "\n" + address + "\n" + to_string(rent) + " kr\n" + habitation + "\n" + to_string(area) + " m2\n" + to_string(rooms) + "\n";
}