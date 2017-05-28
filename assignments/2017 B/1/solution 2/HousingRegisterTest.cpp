//
//  Test.cpp
//  Uppgift A
//
//  Created by Marcus Lenander on 2017-03-20.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "Housing.hpp"
#include "HousingRegister.hpp"

int main() {
    
    cout << "Press enter to start testing" << endl;
    getchar();
    
    //1.
    HousingRegister t(2);
    
    
    //2.
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    t.addHousing(50, 50, 50, "asd", "asd", "asd");
    t.addHousing(5500, 38, 1, "87ide3", "Drottninggatan 42B karlskrona", "Lägenhet");
    string* mynewarr = new string[t.getNrOfHousings()];

    if(t.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < t.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //3.
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    t.addHousing(4000, 28, 1, "ert67", "Drottninggatan 90 karlskrona", "Lägenhet");
    mynewarr = new string[t.getNrOfHousings()];
    t.showHousings(mynewarr);
    
    for(int i = 0; i < t.getNrOfHousings(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //special.
    cout<<"«««««SPECIAL»»»»»"<<endl;
    
    mynewarr = new string[t.getNrOfHousings()];
    
    if(t.showRent(mynewarr, 70) == true)
    {
        for(int i = 0; i < t.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
        
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    
    
    
    mynewarr = new string[t.getNrOfHousings()];
    if(t.showHabRooms(mynewarr, "asd", 50) == true)
    {
        for(int i = 0; i < t.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
        
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //4.
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    if(t.deleteHousing("rrrr4444") != true)
    {
        cout<<"DID NOT DELETE\n"<<endl;
    }
    
    mynewarr = new string[t.getNrOfHousings()];
    
    if(t.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < t.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //5.
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    if(t.deleteHousing("asd") == true)
    {
        cout<<"DELETED\n"<<endl;
    }
    
    mynewarr = new string[t.getNrOfHousings()];
    
    if(t.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < t.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //6.
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    if(t.deleteHousing("87ide3") == true)
    {
        cout<<"DELETED\n"<<endl;
    }
    if(t.deleteHousing("ert67") == true)
    {
        cout<<"DELETED\n"<<endl;
    }

    mynewarr = new string[t.getNrOfHousings()];
    
    if(t.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < t.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //7.
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    t.addHousing(50, 50, 50, "asd", "asd", "asd");
    t.addHousing(5500, 38, 1, "87ide3", "Drottninggatan 42B karlskrona", "Lägenhet");
    mynewarr = new string[t.getNrOfHousings()];
    
    if(t.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < t.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //8.
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    HousingRegister c(t);
    mynewarr = new string[c.getNrOfHousings()];
    
    if(c.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < c.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;

    
    HousingRegister o = t;
    mynewarr = new string[o.getNrOfHousings()];
    
    if(o.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < o.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    
    //Special 2
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;
    o.changeHousing("asd", 4500, 40, 2, "Drottninggatan 42A", "Lägenhet");
    
    mynewarr = new string[o.getNrOfHousings()];
    
    if(o.showHousings(mynewarr) == true)
    {
        for(int i = 0; i < o.getNrOfHousings(); i++)
            cout<<mynewarr[i]<<endl;
    }
    else
        cout<<"empty"<<endl;
    delete[] mynewarr;
    cout<<endl<<"«««««««««»»»»»»»»»"<<endl<<endl;

    //Testar nu dekonstruktor när programmet avslutas.

    return 0;
}