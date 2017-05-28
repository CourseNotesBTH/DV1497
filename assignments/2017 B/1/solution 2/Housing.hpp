//
//  Housing.hpp
//  Uppgift A
//
//  Created by Marcus Lenander on 2017-03-20.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#ifndef Housing_hpp
#define Housing_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Housing
{
private:
    int rent;
    int area;
    int rooms;
    string idNumber;
    string address;
    string habitation;
    
public:
    Housing();
    Housing(int rent, int area, int rooms, string idNumber, string address, string habitation);
    ~Housing();
    
    int getRent() const;
    int getArea() const;
    int getRooms() const;
    string getIdNumber() const;
    string getAddress() const;
    string getHabitation() const;
    void setRent(int rent);
    void setArea(int area);
    void setRooms(int rooms);
    void setIdNumber(string idNumber);
    void setAddress(string address);
    void setHabitation(string habitation);
    
    string toString() const;




};

#endif /* Housing_hpp */
