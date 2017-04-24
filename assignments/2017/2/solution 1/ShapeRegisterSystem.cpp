//
//  TestShapeRegister.cpp
//  Inlämning B
//
//  Created by Alex Gustafsson on 2017-02-21.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include <iostream>
#include <string>

#include "ShapeRegister.hpp"

using namespace std;

void addBox(ShapeRegister& shapeRegister){
    cout << "length width height: ";
    float length, width, height;
    cin >> length >> width >> height;
    shapeRegister.addBox(length, width, height);
}

void addCone(ShapeRegister& shapeRegister){
    cout << "radius height: ";
    float radius, height;
    cin >> radius >> height;
    shapeRegister.addCone(radius, height);
}

void removeShape(ShapeRegister& shapeRegister){
    cout << "height: ";
    float height;
    cin >> height;
    shapeRegister.removeShape(height);
}

// ÄNDRAD: kan nu ändra höjden (som fortfarande måste vara unik)
void editBox(ShapeRegister& shapeRegister){
    cout << "length width height newHeight: ";
    float length, width, height, newHeight;
    cin >> length >> width >> height >> newHeight;
    shapeRegister.editABox(length, width, height, newHeight);
}

// ÄNDRAD: kan nu ändra höjden (som fortfarande måste vara unik)
void editCone(ShapeRegister& shapeRegister){
    cout << "radius height newHeight: ";
    float radius, height, newHeight;
    cin >> radius >> height >> newHeight;
    shapeRegister.editACone(radius, height, newHeight);
}

// ÄNDRAD: använder nu ShapeRegister::nrOfShapes() istället för en godtycklig array-storlek
void displayShapes(const ShapeRegister& shapeRegister) {
    string* strings = new string[shapeRegister.nrOfShapes()];
    shapeRegister.getAllShapesAsString(strings, shapeRegister.nrOfShapes());
    for(int i = 0; i < shapeRegister.nrOfShapes(); i++)
        cout << strings[i] << endl;
    delete[] strings;
}

// ÄNDRAD: använder nu ShapeRegister::nrOfBoxes() istället för en godtycklig array-storlek
void displayBoxes(const ShapeRegister& shapeRegister){
    string* strings = new string[shapeRegister.nrOfBoxes()];
    shapeRegister.getAllBoxesAsString(strings, shapeRegister.nrOfBoxes());
    for(int i = 0; i < shapeRegister.nrOfBoxes(); i++)
        cout << strings[i] << endl;
    delete[] strings;
}

// ÄNDRAD: använder nu ShapeRegister::nrOfCones() istället för en godtycklig array-storlek
void displayCones(const ShapeRegister& shapeRegister){
    string* strings = new string[shapeRegister.nrOfCones()];
    shapeRegister.getAllConesAsString(strings, shapeRegister.nrOfCones());
    for(int i = 0; i < shapeRegister.nrOfCones(); i++)
        cout << strings[i] << endl;
    delete[] strings;
}

int main(int argc, const char * argv[]) {
    ShapeRegister shapeRegister;
    
    bool shouldRun = true;
    do{
        system("clear");
        cout << "1. Add box" << endl;
        cout << "2. Add cone" << endl;
        cout << "3. Remove shape" << endl;
        cout << "4. Edit box" << endl;
        cout << "5. Edit cone" << endl;
        cout << "6. Display all shapes" << endl;
        cout << "7. Display all boxes" << endl;
        cout << "8. Display all cones" << endl;
        cout << "9. Exit" << endl;
        
        
        int menuChoice;
        cin >> menuChoice;
        system("clear");
        getchar();
        switch(menuChoice){
            case 1:
                addBox(shapeRegister);
                break;
            case 2:
                addCone(shapeRegister);
                break;
            case 3:
                removeShape(shapeRegister);
                break;
            case 4:
                editBox(shapeRegister);
                break;
            case 5:
                editCone(shapeRegister);
                break;
            case 6:
                displayShapes(shapeRegister);
                break;
            case 7:
                displayBoxes(shapeRegister);
                break;
            case 8:
                displayCones(shapeRegister);
                break;
            case 9:
                shouldRun = false;
                break;
        }
        cout << "Press enter to continue...";
        getchar();
    } while(shouldRun);
    
    return 0;
}
