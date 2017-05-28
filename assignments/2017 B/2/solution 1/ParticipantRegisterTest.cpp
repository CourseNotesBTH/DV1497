//
//  main.cpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#include "ParticipantRegister.hpp"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    cout<<"Press enter to start testing!"<<endl;
    getchar();
    
    //Börjar med att lägga till 4 deltagare
    ParticipantRegister P;
    P.addExerciser("Male", "Marcus", 21);
    P.addProfessional("Female", "Emma", 2, "Club1");
    P.addExerciser("Female", "Lina", 28);
    P.addProfessional("Male", "Nick", 2, "Club2");
    
    //Testar funktionen som visar alla deltagare och skriver ut dem
    string* mynewarr = new string[P.getNrOfParticipant()];
    P.showParticipant(mynewarr);
    for(int i = 0; i < P.getNrOfParticipant(); i++)
        cout<<mynewarr[i]<<endl;

    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    
    //Testar funktionen som bara visar de profisionella och skriver ut dem
    mynewarr = new string[P.getNrOfProfessional()];
    P.showProfessional(mynewarr);
    for(int i = 0; i < P.getNrOfProfessional(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    
    //testar funktionen som visar bara motionärer och skriver ut dem.
    mynewarr = new string[P.getNrOfExerciser()];
    P.showExerciser(mynewarr);
    for(int i = 0; i < P.getNrOfExerciser(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    
    //Testar att radera en deltagare och sedan skriver ut de för att se så resterande är kvar.
    P.deleteParticipant("Lina");
    mynewarr = new string[P.getNrOfParticipant()];
    P.showParticipant(mynewarr);
    for(int i = 0; i < P.getNrOfParticipant(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    
    //Testar att ändra säsongen för en profisionell och sedan skriver ut för att se så allt stämmer.
    P.changeSeaseon("Emma", 4);
    mynewarr = new string[P.getNrOfParticipant()];
    P.showParticipant(mynewarr);
    for(int i = 0; i < P.getNrOfParticipant(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    
    //testar min sortering och sedan skriver ut oh ser så de verkligen har blivit sorterade.
    P.sortAll();
    mynewarr = new string[P.getNrOfParticipant()];
    P.showParticipant(mynewarr);
    for(int i = 0; i < P.getNrOfParticipant(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    

    //Testar tilldelningsoperator och skriver ut
    ParticipantRegister P2 = P;
    mynewarr = new string[P2.getNrOfParticipant()];
    P2.showParticipant(mynewarr);
    for(int i = 0; i < P2.getNrOfParticipant(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    cout<<"«««««««««««»»»»»»»»»»»"<<endl;
    
    //Testar copy - konstruktor och skriver ut.
    ParticipantRegister P3(P);
    mynewarr = new string[P3.getNrOfParticipant()];
    P3.showParticipant(mynewarr);

    for(int i = 0; i < P3.getNrOfParticipant(); i++)
        cout<<mynewarr[i]<<endl;
    delete[] mynewarr;


    //Testar nu destruktor när programet avslutas.
	getchar();
    return 0;
}
