//
//  ShapeRegister.hpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-20.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#ifndef ShapeRegister_hpp
#define ShapeRegister_hpp

#include "Shape.hpp"
#include "Box.hpp"
#include "Cone.hpp"

#include <string>

class ShapeRegister{
private:
    Shape** shapes;
    // Actual capacity of the array
    int capacity;
    // Added cones & boxes
    int cones;
    int boxes;
    void free();
    void expand();
    int indexOf(float height) const;
    bool contains(float height) const;
public:
    ShapeRegister();
    ShapeRegister(const ShapeRegister& other);
    ShapeRegister& operator=(const ShapeRegister& other);
    ~ShapeRegister();
    bool addCone(float radius, float height);
    bool addBox(float length, float width, float height);
    bool removeShape(float height);
    bool getAllShapesAsString(std::string array[], int capOfArray) const;
    bool getAllBoxesAsString(std::string array[], int capOfArray) const;
    bool getAllConesAsString(std::string array[], int capOfArray) const;
    // ÄNDRAD: ändrar nu height
    bool editACone(float radius, float height, float newHeight);
    // ÄNDRAD: ändrar nu height
    bool editABox(float length, float width, float height, float newHeight);
    int nrOfShapes() const;
    // INTE ÄNDRADE: föredra mikro-optimeringen här (slipp loopa igenom varje gång) även YAGNI i kontext
    int nrOfCones() const;
    int nrOfBoxes() const;
};

#endif /* ShapeRegister_hpp */
