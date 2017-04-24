//
//  HousingRegister.hpp
//  Inlämning A 2
//
//  Created by Alex Gustafsson on 2017-03-17.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#ifndef HousingRegister_hpp
#define HousingRegister_hpp

#include "Housing.hpp"

class HousingRegister{
private:
    Housing** housings;
    
    int capacity;
    int count;
    
    void expand();
public:
    HousingRegister();
    HousingRegister(int capacity);
    HousingRegister(const HousingRegister& other);
    ~HousingRegister();
    
    bool operator == (const HousingRegister& other) const;
    bool operator != (const HousingRegister& other) const;
    HousingRegister& operator = (const HousingRegister other);
    
    bool addHousing(int id, std::string address, float rent, std::string type, float livingArea, int roomCount);
    
    bool removeHousing(int id);
    
    bool changeHousing(int id, std::string address, float rent, std::string type, float livingArea, int roomCount);
    
    int getCount() const;
    
    bool fetchStrings(std::string* array, int capacity) const;
    bool fetchStrings(std::string* array, int capacity, float maximumRent) const;
    bool fetchStrings(std::string* array, int capacity, std::string type, int roomCount) const;
    
    bool housingExists(int id) const;
    
    void save(std::string filename) const;
    void read(std::string filename);
};

#endif /* HousingRegister_hpp */
