//
//  ShapeRegister.cpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include "ShapeRegister.hpp"

ShapeRegister::ShapeRegister() : capacity(0), cones(0), boxes(0) {
    this->shapes = new Shape*[this->capacity];
}

ShapeRegister::ShapeRegister(const ShapeRegister& other){
    this->capacity = other.capacity;
    this->boxes = other.boxes;
    this->cones = other.cones;
    
    this->shapes = new Shape*[other.capacity];
    
    for(int i = 0; i < other.capacity; i++){
        this->shapes[i] = other.shapes[i]->clone();
    }
}

ShapeRegister& ShapeRegister::operator=(const ShapeRegister& other){
    if(this != &other){
        this->free();
        
        this->capacity = other.capacity;
        this->boxes = other.boxes;
        this->cones = other.cones;
        
        this->shapes = new Shape*[other.capacity];
        
        for(int i = 0; i < other.capacity; i++){
            this->shapes[i] = other.shapes[i]->clone();
        }
    }
    return *this;
}

void ShapeRegister::free(){
    for(int i = 0; i < this->nrOfShapes(); i++)
        delete this->shapes[i];
    delete[] this->shapes;
}

ShapeRegister::~ShapeRegister(){
    this->free();
}

void ShapeRegister::expand(){
    Shape** newArray = new Shape*[this->capacity + 1];
    
    for(int i = 0; i < this->capacity; i++){
        newArray[i] = this->shapes[i];
    }
    
    delete[] this->shapes;
    this->shapes = newArray;
    this->capacity++;
}

int ShapeRegister::indexOf(float height) const{
    int index = -1;
    for(int i = 0; i < this->nrOfShapes(); i++){
        if(this->shapes[i]->getHeight() == height){
            index = i;
            break;
        }
    }
    return index;
}

bool ShapeRegister::contains(float height) const{
    return this->indexOf(height) != -1;
}

bool ShapeRegister::addCone(float radius, float height){
    bool added = false;

    if(!this->contains(height)){
        if(this->nrOfShapes() == this->capacity)
            this->expand();
        this->shapes[this->nrOfShapes()] = new Cone(radius, height);
        this->cones++;
        added = true;
    }
    
    return added;
}

bool ShapeRegister::addBox(float length, float width, float height){
    bool added = false;
    
    if(!this->contains(height)){
        if(this->nrOfShapes() == this->capacity)
            this->expand();
        this->shapes[this->nrOfShapes()] = new Box(length, width, height);
        this->boxes++;
        added = true;
    }
    
    return added;
}

bool ShapeRegister::removeShape(float height){
    bool removed = false;
    int index = this->indexOf(height);
    if(index != -1){
        if(dynamic_cast<Box*>(this->shapes[index]))
            this->boxes--;
        else
            this->cones--;
        delete this->shapes[index];
        for(int i = index; i < this->capacity - 1; i++)
            this->shapes[i] = this->shapes[i + 1];
        removed = true;
    }
    
    return removed;
}

bool ShapeRegister::getAllShapesAsString(std::string array[], int capOfArray) const{
    bool filled = false;
    
    // ÄNDRAD: fixade typo, <= ska det vara - inte <
    if(this->nrOfShapes() <= capOfArray){
        for(int i = 0; i < this->nrOfShapes(); i++)
            array[i] = this->shapes[i]->toString();
        filled = true;
    }

    return filled;
}

bool ShapeRegister::getAllBoxesAsString(std::string array[], int capOfArray) const{
    bool filled = false;
    
    // ÄNDRAD: fixade typo, <= ska det vara - inte <
    if(this->nrOfBoxes() <= capOfArray){
        int nrOfAdded = 0;
        for(int i = 0; i < this->nrOfShapes(); i++){
            if(dynamic_cast<Box*>(this->shapes[i])){
                array[nrOfAdded] = this->shapes[i]->toString();
                nrOfAdded++;
            }
        }
        filled = true;
    }
    
    return filled;
}

bool ShapeRegister::getAllConesAsString(std::string array[], int capOfArray) const{
    bool filled = false;
    
    // ÄNDRAD: fixade typo, <= ska det vara - inte <
    if(this->nrOfCones() <= capOfArray){
        int nrOfAdded = 0;
        for(int i = 0; i < this->nrOfShapes(); i++){
            if(dynamic_cast<Cone*>(this->shapes[i])){
                array[nrOfAdded] = this->shapes[i]->toString();
                nrOfAdded++;
            }
        }
        filled = true;
    }
    
    return filled;
}

// ÄNDRAD: ändrar nu height
bool ShapeRegister::editACone(float radius, float height, float newHeight){
    bool edited = false;
    int indexToEdit = this->indexOf(height);
    int indexOfCollision = this->indexOf(newHeight);
    if(indexToEdit != -1 && indexOfCollision == -1){
        if(Cone* cone = dynamic_cast<Cone*>(this->shapes[indexToEdit])){
            cone->setRadius(radius);
            cone->setHeight(newHeight);
            edited = true;
        }
    }
    
    return edited;
}

// ÄNDRAD: ändrar nu height
bool ShapeRegister::editABox(float length, float width, float height, float newHeight){
    bool edited = false;
    int indexToEdit = this->indexOf(height);
    int indexOfCollision = this->indexOf(newHeight);
    if(indexToEdit != -1 && indexOfCollision == -1){
        if(Box* box = dynamic_cast<Box*>(this->shapes[indexToEdit])){
            box->setLength(length);
            box->setWidth(width);
            box->setHeight(newHeight);
            edited = true;
        }
    }
    
    return edited;
}

int ShapeRegister::nrOfShapes() const{
    return this->nrOfCones() + this->nrOfBoxes();
}

// INTE ÄNDRADE: föredra mikro-optimeringen här (slipp loopa igenom varje gång) även YAGNI i kontext
int ShapeRegister::nrOfCones() const{
    return this->cones;
}

// INTE ÄNDRADE: föredra mikro-optimeringen här (slipp loopa igenom varje gång) även YAGNI i kontext
int ShapeRegister::nrOfBoxes() const{
    return this->boxes;
}
