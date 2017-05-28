//
//  main.cpp
//  Inlämning A 2
//
//  Created by Alex Gustafsson on 2017-03-17.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include <iostream>
#include "HousingRegister.hpp"

using namespace std;

void writeStrings(const HousingRegister& housingRegister){
    string* strings = new string[housingRegister.getCount()];
    cout << "Gettings strings" << endl;
    strings = new string[housingRegister.getCount()];
    housingRegister.fetchStrings(strings, housingRegister.getCount());
    for(int i = 0; i < housingRegister.getCount(); i++)
        cout << strings[i] << endl;
    delete[] strings;
}

int testMain (int argc, const char * argv[]) {
    cout << "Creating a register A" << endl;
    HousingRegister registerA(2);
    
    cout << "Adding two housings" << endl;
    registerA.addHousing(1, "Park Lane 331", 5000, "Appartment", 110, 3);
    registerA.addHousing(2, "Boulevard of broken dreams", 1250, "Studio appartment", 40, 1);
    
    writeStrings(registerA);
    
    cout << "Adding another housing, triggering expansion" << endl;
    registerA.addHousing(5, "Somwhere only we know", 12000, "House", 300, 6);
    
    writeStrings(registerA);
    
    cout << "Removing an accomodation that do not exist" << endl;
    cout << "Removed 10? " << (registerA.removeHousing(10) ? "true" : "false") << endl;
    
    writeStrings(registerA);
    
    cout << "Removing an accomodation that do exist" << endl;
    cout << "Removed 1? " << (registerA.removeHousing(1) ? "true" : "false") << endl;
    
    writeStrings(registerA);
    
    cout << "Removing remaining housings" << endl;
    cout << "Removed 2? " << (registerA.removeHousing(2) ? "true" : "false") << endl;
    cout << "Removed 5? " << (registerA.removeHousing(5) ? "true" : "false") << endl;
    
    writeStrings(registerA);
    
    cout << "Adding two housings" << endl;
    registerA.addHousing(1, "Park Lane 331", 5000, "Appartment", 110, 3);
    registerA.addHousing(2, "Boulevard of broken dreams", 1250, "Studio appartment", 40, 1);
    
    writeStrings(registerA);
    
    cout << "Creating a copy B of register A" << endl;
    HousingRegister registerB(registerA);
    
    writeStrings(registerB);
    
    cout << "Creating an empty register C" << endl;
    HousingRegister registerC;
    
    writeStrings(registerC);
    
    cout << "Assigning A to C" << endl;
    registerC = registerA;
    
    writeStrings(registerC);
    
    return 0;
}
