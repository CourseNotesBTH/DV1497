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

int testMain(int argc, const char * argv[]) {
    // För mindre kod, använd samma buffer hela tiden, därav hårdkodad (något väl tilltagen) längd
    string* strings = new string[100];
    
    ShapeRegister shapeRegister1;
    shapeRegister1.addBox(51, 21, 32);
    shapeRegister1.addBox(1, 53, 71);
    shapeRegister1.addBox(23, 73, 51);
    shapeRegister1.addBox(14, 45, 41);
    cout << "Shape register 1 (initialized using default constructor)" << endl;
    shapeRegister1.getAllShapesAsString(strings, 100);
    for(int i = 0; i < shapeRegister1.nrOfShapes(); i++)
        cout << strings[i] << endl;
    
    ShapeRegister shapeRegister2(shapeRegister1);
    cout << "Shape register 2 (initialized using copy constructor)" << endl;
    shapeRegister2.getAllShapesAsString(strings, 100);
    for(int i = 0; i < shapeRegister2.nrOfShapes(); i++)
        cout << strings[i] << endl;
    
    
    // ÄNDRAD: lagt till några Box innan tilldelningsoperator används
    ShapeRegister shapeRegister3;
    cout << "Adding some shapes to shape register 3" << endl;
    shapeRegister3.addBox(16, 06, 07);
    shapeRegister3.addBox(20, 12, 12);
    shapeRegister3.addBox(11, 11, 11);
    cout << "Shape register 3 (initialized using default constructor)" << endl;
    shapeRegister3.getAllShapesAsString(strings, 100);
    for(int i = 0; i < shapeRegister3.nrOfShapes(); i++)
        cout << strings[i] << endl;
    shapeRegister3 = shapeRegister2;
    cout << "Shape register 3 (initialized using default constructor, then assigned)" << endl;
    shapeRegister3.getAllShapesAsString(strings, 100);
    for(int i = 0; i < shapeRegister3.nrOfShapes(); i++)
        cout << strings[i] << endl;
    
    cout << "Will now delete all registers and throw errors if memory was not deallocated correctly" << endl;
    
    // ÄNDRAD: fixat minneslucka
    delete[] strings;
    
    return 0;
}
