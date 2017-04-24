//
//  Box.cpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include "Box.hpp"
#include <sstream>

Box::Box() : Box(0, 0, 0) {}

// ÄNDRAD: använder nu Shapes funktion för att ändra height
Box::Box(float length, float width, float height) : length(length), width(width) {
    this->setHeight(height);
}

Box::Box(const Box& other) : length(other.length), width(other.width) {
    this->setHeight(other.getHeight());
}

Box& Box::operator=(const Box& other){
    if(this != &other){
        this->length = other.length;
        this->width = other.width;
        this->setHeight(other.getHeight());
    }
    return *this;
}

Box* Box::clone() const {
    return new Box(*this);
}

Box::~Box(){
    
}

float Box::getLength() const{
    return this->length;
}

void Box::setLength(float length){
    this->length = length;
}

float Box::getWidth() const{
    return this->width;
}

void Box::setWidth(float width){
    this->width = width;
}

float Box::getVolume() const{
    return this->length * this->width * this->getHeight();
}

// ÄNDRAD: låter Shape ta hand om height-utskrift
std::string Box::toStringSpecific() const{
    std::stringstream stream;
    stream << "Length:\t" << this->length << "\n\t";
    stream << "Width:\t" << this->width << "\n\t";
    return stream.str();
}
