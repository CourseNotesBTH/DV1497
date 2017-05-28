//
//  main.cpp
//  Uppgift C 2
//
//  Created by Marcus Lenander on 2017-04-02.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "Set.hpp"


int main()
{
    
    cout<<"Hit Enter To Start"<<endl;
    getchar();
    
    //Startar med att sätta kapaciteten till 2 och sedan lägger till 5 element därav ska expand triggas.
    Set<int> digit(2);
    digit.insert(10);
    digit.insert(20);
    digit.insert(30);
    digit.insert(40);
    digit.insert(50);
    
    //testar så att den retunerar false om elementet redan finns.
    if(digit.insert(50) == false)
        cout<<"Duplicate"<<endl;
    
    //testar copy - konstruktorn, kollar så att den har förtöver rätt antal element och att size fungerar. Ska retunera 5.
    Set<int> digit2(digit);
    cout<<digit2.size()<<endl;
    
    //Raderar alla element ifrån listan som skapades av copy kosnt.
    digit2.remove(10);
    digit2.remove(20);
    digit2.remove(30);
    digit2.remove(40);
    digit2.remove(50);
    
    //testar size funktionen. bör retunera 0
    cout<<digit2.size()<<endl;
    
    //testar tilldelnings operatorn, kollar så att den har förtöver rätt antal element och att size fungerar. Ska retunera 5.
    Set<int> digit3 = digit;
    cout<<digit3.size()<<endl;
    
    //Raderar alla element ifrån listan som skapades av tilldelnings
    digit3.remove(10);
    digit3.remove(20);
    digit3.remove(30);
    digit3.remove(40);
    digit3.remove(50);
    
    //testar size funktionen. bör retunera 0
    cout<<digit3.size()<<endl;
    
    //Testar att radera ett element som inte finns
    try{
    digit3.remove(10);
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    
    cout<<"««««««««««««««««««Next Step»»»»»»»»»»»»»»»»»»"<<endl;
    
    
    //Testar nu samma fast för String.
    //Startar med att sätta kapaciteten till 2 och sedan lägger till 5 element därav ska expand triggas.
    Set<string> strings(2);
    strings.insert("aa");
    strings.insert("bb");
    strings.insert("cc");
    strings.insert("dd");
    strings.insert("ee");
    
    //testar så att den retunerar false om elementet redan finns.
    if(strings.insert("ee") == false)
        cout<<"Duplicate"<<endl;
    
    //testar copy - konstruktorn, kollar så att den har förtöver rätt antal element.
    Set<string> strings2(strings);
    cout<<strings2.size()<<endl;
    
    //testar Tilldelningsoperatorn, kollar så att den har förtöver rätt antal element.
    Set<string> strings3 = strings;
    cout<<strings3.size()<<endl;
    
    //testar size funktionen. bör retunera 5
    cout<<strings.size()<<endl;
    
    //Testar att ta bort ett element.
    strings.remove("cc");
    
    //kollar så att det har försvunnit ur mängden
    cout<<strings.size()<<endl;
    
    //Testar att radera ett element som inte finns
    try{
        strings.remove("xx");
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    
    
    
    
    
    //testar nu destruktor när programmet avslutas
    return 0;
}
