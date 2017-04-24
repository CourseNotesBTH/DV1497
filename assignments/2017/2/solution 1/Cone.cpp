//
//  Cone.cpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include "Cone.hpp"
#include <sstream>
#include <math.h>

Cone::Cone() : Cone(0, 0) {}

// ÄNDRAD: använder nu Shapes funktion för att ändra height
Cone::Cone(float radius, float height) : radius(radius) {
    this->setHeight(height);
}

Cone::Cone(const Cone& other) : radius(other.radius) {
    this->setHeight(other.getHeight());
}

Cone& Cone::operator=(const Cone& other){
    if(this != &other){
        this->radius = other.radius;
        this->setHeight(other.getHeight());
    }
    return *this;
}

Cone::~Cone(){
    
}

Cone* Cone::clone() const {
    return new Cone(*this);
}

float Cone::getRadius() const{
    return this->radius;
}

void Cone::setRadius(float radius){
    this->radius = radius;
}

// ÄNDRAD: hämta height från Shape
float Cone::getVolume() const{
    return M_PI * pow(this->radius, 2) * this->getHeight() / 3;
}

// ÄNDRAD: låter Shape ta hand om height-utskrift
std::string Cone::toStringSpecific() const{
    std::stringstream stream;
    stream << "Radius:\n\t" << this->radius << std::endl;
    return stream.str();
}
