//
//  Shape.cpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include "Shape.hpp"
#include <sstream>

Shape::Shape(){
    this->height = 0;
}

Shape::Shape(const Shape& other){
    this->height = other.height;
}

Shape::~Shape(){}

// ÄNDRAD: tar nu hand om utskrift av height
std::string Shape::toString() const{
    std::stringstream stream;
    stream << "Shared:\n\t";
    stream << "Height:\t" << this->height << std::endl;
    stream << "Volume:\t" << this->getVolume() << std::endl;
    stream << "Specific:\n\t" << this->toStringSpecific();
    return stream.str();
}

// ÄNDRAD: sköter nu height
float Shape::getHeight() const{
    return this->height;
}
void Shape::setHeight(float height){
    this->height = height;
}

Shape::operator std::string() const{
    return this->toString();
}

std::ostream& operator << (std::ostream &stream, const Shape &shape){
    stream << shape.toString();
    return stream;
}

// ÄNDRAD: nu markerad som const
bool Shape::operator == (const Shape& other) const{
    return this->getHeight() == other.getHeight();
}

// ÄNDRAD: nu markerad som const
bool Shape::operator != (const Shape& other) const{
    return !(*this == other);
}
