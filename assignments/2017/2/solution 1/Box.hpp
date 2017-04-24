//
//  Box.hpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include "Shape.hpp"
#include <string>

class Box : public Shape {
private:
    float length;
    float width;
    std::string toStringSpecific() const;
public:
    Box();
    Box(float length, float width, float height);
    Box(const Box& other);
    Box& operator=(const Box& other);
    ~Box();
    
    float getLength() const;
    void setLength(float length);
    
    float getWidth() const;
    void setWidth(float width);
        
    float getVolume() const;
    
    Box* clone() const;
};

#endif /* Box_hpp */
