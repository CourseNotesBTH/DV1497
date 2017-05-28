//
//  HousingRegister.hpp
//  Uppgift A
//
//  Created by Marcus Lenander on 2017-03-20.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#ifndef HousingRegister_hpp
#define HousingRegister_hpp

#include "Housing.hpp"

class HousingRegister
{
private:
    Housing** housingArray;
    int cap;
    int nrOfHousing;
    int findId(string idNumber);
    void expand();
    
public:
    HousingRegister();
    HousingRegister(int cap);
    HousingRegister(const HousingRegister &origObj);
    HousingRegister &operator=(const HousingRegister &origObj);
    ~HousingRegister();
    
    int getNrOfHousings() const;
    bool addHousing(int rent, int area, int rooms, string idNumber, string address, string habitation);
    bool showHousings(string aString[]) const;
    bool showRent(string *aString, int rent) const;
    bool showHabRooms(string aString[], string habitation, int rooms) const;
    bool deleteHousing(const string & idNumber);
    bool changeHousing(const string & idNumber, int rent, int area, int rooms, string address, string habitation);
    void read(string filename);
    void save(string filename) const;
};

#endif /* HousingRegister_hpp */
