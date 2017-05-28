//
//  Housing.hpp
//  Inlämning A 2
//
//  Created by Alex Gustafsson on 2017-03-17.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#ifndef Housing_hpp
#define Housing_hpp

#include <string>

class Housing {
private:
    int id;
    std::string address;
    float rent;
    std::string type;
    float livingArea;
    int roomCount;
public:
    Housing();
    Housing(const Housing& other);
    Housing(int id, std::string address, float rent, std::string type, float livingArea, int roomCount);
   
    bool operator == (const Housing& other) const;
    bool operator != (const Housing& other) const;
    Housing& operator = (const Housing other);
    
    std::string toString() const;
    
    int getId() const;
    
    std::string getAddress() const;
    void setAddress(std::string address);
    
    float getRent() const;
    void setRent(float rent);
    
    std::string getType() const;
    void setType(std::string type);
    
    int getLivingArea() const;
    void setLivingArea(int livingArea);
    
    int getRoomCount() const;
    void setRoomCount(int roomCount);
};

#endif /* Housing_hpp */
