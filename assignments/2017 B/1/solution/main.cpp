//
//  TimberRegisterSystem.cpp
//  Inlämning A
//
//  Created by Alex Gustafsson on 2017-01-30.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include <iostream>
#include <string>

#include "HousingRegister.hpp"

using namespace std;

void printMenu(){
    cout << "=========================" << endl;
    cout << "           io" << endl;
    cout << "1. Display all information" << endl;
    cout << "2. Save to file" << endl;
    cout << "3. Read from file" << endl;
    cout << "         search" << endl;
    cout << "4. Housing meeting some criteria" << endl;
    cout << "5. Housing with less than x rent" << endl;
    cout << "        operations" << endl;
    cout << "6. Add housing" << endl;
    cout << "7. Remove housing" << endl;
    cout << "8. Change housing" << endl;
    cout << "\n9. Exit\n" << endl;
}

/*
 Use the preprocessor to figure out the current environment,
 then runs the clear command - makes it a bit more portable.
 Note: assumes all non-Windows systems use "clear"
 */
void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void wait(){
    cout << "\nPress the enter key to continue" << endl;
    getchar(); //wait for user input
    getchar();
}

void printAll(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "        all info" << endl;
    
    string array[storage.getCount()];
    storage.fetchStrings(array, storage.getCount());
    for(int i = 0; i < storage.getCount(); i++)
        cout << array[i] << endl;
    
    wait();
}

void searchHousingRent(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "         search" << endl;
    
    float maxRent = -1;
    do {
        cout << "Maximum rent: " << endl;
        cin >> maxRent;
        
        if(!(maxRent >= 1))
            cout << "I'm sorry, that is an invalid maximum rent." << endl;
    } while (!(maxRent >= 1));
    
    string array[storage.getCount()];
    storage.fetchStrings(array, storage.getCount(), maxRent);
    for(int i = 0; i < storage.getCount(); i++)
        cout << array[i] << endl;
    
    wait();
}

void searchHousingCriteria(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "         search" << endl;
    
    string type = "";
    do {
        cout << "Type: " << endl;
        cin >> type;
        
        if(type == "")
            cout << "I'm sorry, that is an invalid type." << endl;
    } while (type == "");
    
    int roomCount = -1;
    do {
        cout << "Number of rooms: " << endl;
        cin >> roomCount;
        
        if(!(roomCount >= 1))
            cout << "I'm sorry, that is an invalid type." << endl;
    } while (!(roomCount >= 1));
    
    string array[storage.getCount()];
    storage.fetchStrings(array, storage.getCount(), type, roomCount);
    for(int i = 0; i < storage.getCount(); i++)
        cout << array[i] << endl;
    
    wait();
}

void removeHousing(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "     remove housing" << endl;
    
    string array[storage.getCount()];
    storage.fetchStrings(array, storage.getCount());
    for(int i = 0; i < storage.getCount(); i++)
        cout << i+1 << ". " << array[i] << endl;
    
    int id = -1;
    do {
        cout << "Id to change: ";
        cin >> id;
        
        if(!(storage.housingExists(id)))
            cout << "I'm sorry, that is an invalid id." << endl;
    } while (!(storage.housingExists(id)));
    getchar();
    
    storage.removeHousing(id);
}

void changeHousing(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "      change housing" << endl;
    
    string array[storage.getCount()];
    storage.fetchStrings(array, storage.getCount());
    for(int i = 0; i < storage.getCount(); i++)
        cout << i+1 << ". " << array[i] << endl;
    
    int id = -1;
    do {
        cout << "Id to change: " << endl;
        cin >> id;
        
        if(!(storage.housingExists(id)))
            cout << "I'm sorry, that is an invalid id." << endl;
    } while (!(storage.housingExists(id)));
    getchar();
    
    string type = "";
    do {
        cout << "Type: " << endl;
        cin >> type;
        
        if(type == "")
            cout << "I'm sorry, that is an invalid type." << endl;
    } while (type == "");
    
    string address = "";
    do {
        cout << "Address: " << endl;
        cin >> address;
        
        if(address == "")
            cout << "I'm sorry, that is an invalid address." << endl;
    } while (address == "");
    
    int roomCount = -1;
    do {
        cout << "Number of rooms: " << endl;
        cin >> roomCount;
        
        if(!(roomCount >= 1))
            cout << "I'm sorry, that is an invalid type." << endl;
    } while (!(roomCount >= 1));
    
    float rent = -1;
    do {
        cout << "Rent: " << endl;
        cin >> rent;
        
        if(!(rent >= 1))
            cout << "I'm sorry, that is an invalid rent." << endl;
    } while (!(rent >= 1));
    
    float livingArea = -1;
    do {
        cout << "Living area: " << endl;
        cin >> livingArea;
        
        if(!(livingArea >= 1))
            cout << "I'm sorry, that is an invalid living area." << endl;
    } while (!(livingArea >= 1));
    
    storage.changeHousing(id, address, rent, type, livingArea, roomCount);
}

void saveRegister(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "      save timber" << endl;
    
    string filename;
    
    cout << "Where would you like to save your file? " << endl;
    getchar();
    getline(cin, filename);
    
    storage.save(filename);
}

void readRegister(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "      read timber" << endl;
    
    string filename;
    
    cout << "What file would you like to read? " << endl;
    getchar();
    getline(cin, filename);
    
    storage.read(filename);
}

void addHousing(HousingRegister& storage){
    clearScreen();
    cout << "=========================" << endl;
    cout << "       add housing" << endl;
    
    int id = -1;
    do {
        cout << "Id: " << endl;
        cin >> id;
        
        if(storage.housingExists(id))
            cout << "I'm sorry, that is an invalid id." << endl;
    } while (storage.housingExists(id));
    getchar();
    
    string type = "";
    do {
        cout << "Type: " << endl;
        cin >> type;
        
        if(type == "")
            cout << "I'm sorry, that is an invalid type." << endl;
    } while (type == "");

    string address = "";
    do {
        cout << "Address: " << endl;
        cin >> address;
        
        if(address == "")
            cout << "I'm sorry, that is an invalid address." << endl;
    } while (address == "");
    
    int roomCount = -1;
    do {
        cout << "Number of rooms: " << endl;
        cin >> roomCount;
        
        if(!(roomCount >= 1))
            cout << "I'm sorry, that is an invalid type." << endl;
    } while (!(roomCount >= 1));
    
    float rent = -1;
    do {
        cout << "Rent: " << endl;
        cin >> rent;
        
        if(!(rent >= 1))
            cout << "I'm sorry, that is an invalid rent." << endl;
    } while (!(rent >= 1));
    
    float livingArea = -1;
    do {
        cout << "Living area: " << endl;
        cin >> livingArea;
        
        if(!(livingArea >= 1))
            cout << "I'm sorry, that is an invalid living area." << endl;
    } while (!(livingArea >= 1));
    
    storage.addHousing(id, address, rent, type, livingArea, roomCount);
    
    wait();
}

int main(int argc, const char * argv[]) {
    HousingRegister storage;
    bool shouldRun = true;
    
    do {
        clearScreen();
        printMenu();
        
        int menuChoice = -1;
        do {
            cout << "Operation: ";
            cin >> menuChoice;
            
            if(!(menuChoice > 0 && menuChoice <= 9))
                cout << "I'm sorry, that option is not available." << endl;
        } while (!(menuChoice > 0 && menuChoice <= 9));
        
        switch(menuChoice){
            case 1:
                printAll(storage);
                break;
            case 2:
                saveRegister(storage);
                break;
            case 3:
                readRegister(storage);
                break;
            case 4:
                searchHousingCriteria(storage);
                break;
            case 5:
                searchHousingRent(storage);
                break;
            case 6:
                addHousing(storage);
                break;
            case 7:
                removeHousing(storage);
                break;
            case 8:
                changeHousing(storage);
                break;
            case 9:
                shouldRun = false;
                break;
        }
        
    } while (shouldRun);
    
    return 0;
}
