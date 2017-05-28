//
//  main.cpp
//  Uppgift A
//
//  Created by Marcus Lenander on 2017-03-20.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "HousingRegister.hpp"

void addHousing(HousingRegister &H)
{
    int rent, area, rooms;
    string idNumber, address, habitation, filename;
    
    cout<<"«««««Add Housing»»»»»»"<<endl;
    
    cout<<"Rent: ";
    cin>>rent;
    cout<<"Area: ";
    cin>>area;
    cout<<"Rooms: ";
    cin>>rooms;
    cout<<"Id number: ";
    cin>>idNumber;
    cout<<"Address: ";
    cin>>address;
    getchar();
    cout<<"Habitation: ";
    cin>>habitation;
    
    if(H.addHousing(rent, area, rooms, idNumber, address, habitation) == true)
        cout<<"Added Successfully"<<endl;
    else
        cout<<"Did Not Add"<<endl;
    
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
}
void showHousings(HousingRegister &H)
{
    string* mynewarr = new string[H.getNrOfHousings()];
    
    cout<<"«««Display Housings»»»"<<endl;
    
    if(H.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < H.getNrOfHousings(); i++)
            cout<<i+1<<"# "<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
}
void showRent(HousingRegister &H)
{
    int rent;
    string* mynewarr = new string[H.getNrOfHousings()];
    
    cout<<"«««Rent Lower Then»»»»"<<endl;
    cout<<"Rent To Search for: ";
    cin>>rent;
    cout<<"\n";
    
    if(H.showRent(mynewarr, rent) == true)
    {
        for(int i = 0; i < H.getNrOfHousings(); i++)
            cout<<i+1<<"# "<<mynewarr[i]<<endl;
        
    }
    else
        cout<<"No Housings Available"<<endl;
    
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
}
void showHabRooms(HousingRegister &H)
{
    string* mynewarr = new string[H.getNrOfHousings()];
    
    cout<<"«Rooms And Habitation»"<<endl;
    
    if(H.showHabRooms(mynewarr, "asd", 50) == true)
    {
        for(int i = 0; i < H.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
        
    }
    else
        cout<<"empty"<<endl;
    
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;

}
void deleteHousing(HousingRegister &H)
{
    string idNumber;
    
    cout<<"««««Delete Housing»»»»"<<endl;
    cout<<"Id Number To Search For: ";
    cin>>idNumber;
    
    if(H.deleteHousing(idNumber) != true)
    {
        cout<<"Did Not Delete"<<endl;
    }
    else
        cout<<"Deleted Successfully"<<endl;
    
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
}
void changeHousing(HousingRegister &H)
{
    int rent, area, rooms;
    string idNumber, address, habitation, filename;
    
    cout<<"««««Change Housing»»»»"<<endl;
    
    cout<<"Id number: ";
    cin>>idNumber;
    cout<<"New Rent: ";
    cin>>rent;
    cout<<"New Area: ";
    cin>>area;
    cout<<"New Rooms: ";
    cin>>rooms;
    cout<<"New Address: ";
    cin>>address;
    getchar();
    cout<<"New Habitation: ";
    cin>>habitation;
    
    if(H.changeHousing(idNumber, rent, area, rooms, address, habitation) == true)
        cout<<"Edited Successfully"<<endl;
    else
        cout<<"Did Not Edit"<<endl;
    
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
}
void read(HousingRegister &H)
{
    string filename;
    
    cout<<"«««««Read Housing»»»»»"<<endl;
    
    cout<<"Destination To Read From: ";
    cin>>filename;
    H.read(filename);
    
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;

}
void save(HousingRegister &H)
{
    string filename;
    
    cout<<"«««««Save Housing»»»»»"<<endl;
    
    cout<<"Destination To Save At: ";
    cin>>filename;
    H.save(filename);
    
    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;

}
int main()
{
    int m;
    HousingRegister H;
    string idNumber, address, habitation, filename;
    
    do{
        cout<<"HOUSING REGISTER"<<endl;;
        cout<<"1. Add Housing"<<endl;
        cout<<"2. Display All Housings"<<endl;
        cout<<"3. Display Housings With Rent Lower Than"<<endl;
        cout<<"4. Display Housings Based On Rooms And Habitation"<<endl;
        cout<<"5. Delete Specific Housing"<<endl;
        cout<<"6. Change Specific Housing"<<endl;
        cout<<"7. Save Housings To Txt"<<endl;
        cout<<"8. Read Housings From Txt"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"\nEnter digit [0-8]# ";
        cin >> m;
        getchar();
        
        switch(m){
            case 1:
                addHousing(H);
                break;
                
            case 2:
                showHousings(H);
                break;
                
            case 3:
                showRent(H);
                break;
                
            case 4:
                showHabRooms(H);
                break;
                
            case 5:
                deleteHousing(H);
                break;
            
            case 6:
                changeHousing(H);
                break;
                
            case 7:
                save(H);
                break;
                
            case 8:
                read(H);
                break;
                
            default:
                if(m != 0)
                    cout<<"\n««ERROR»»\nMust be [0-8]...\n\n";
                break;
        }
    }while(m != 0);
    
   
    return 0;
}



