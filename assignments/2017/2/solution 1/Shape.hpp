//
//  Shape.hpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <string>
#include <iostream>

class Shape {
private:
    float height;
    virtual std::string toStringSpecific() const=0;
protected:
    Shape();
    Shape(const Shape& other);
public:
    virtual ~Shape()=0;
    
    float getHeight() const;
    void setHeight(float height);
    
    virtual float getVolume() const=0;
    
    std::string toString() const;
    operator std::string() const;
    friend std::ostream& operator << (std::ostream &stream, const Shape &shape);
    
    virtual Shape* clone() const=0;
    
    // ÄNDRAD: nu markerade som const
    bool operator == (const Shape& other) const;
    bool operator != (const Shape& other) const;
};
#endif /* Shape_hpp */
