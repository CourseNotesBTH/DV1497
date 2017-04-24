//
//  Cone.hpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#ifndef Cone_hpp
#define Cone_hpp

#include "Shape.hpp"
#include <string>

class Cone : public Shape {
private:
    float radius;
    std::string toStringSpecific() const;
public:
    Cone();
    Cone(float radius, float height);
    Cone(const Cone& other);
    Cone& operator=(const Cone& other);
    ~Cone();
    
    float getRadius() const;
    void setRadius(float length);
    
    float getVolume() const;
    
    Cone* clone() const;
};

#endif /* Cone_hpp */
