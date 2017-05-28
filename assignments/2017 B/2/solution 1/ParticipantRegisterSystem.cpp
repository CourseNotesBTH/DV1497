////
////  ParticipantRegisterSystem.cpp
////  TävlingsDeltagare
////
////  Created by Marcus Lenander on 2017-04-02.
////  Copyright © 2017 Marcus Lenander. All rights reserved.
////
//
//#define _CRTDBG_MAP_ALLOC  
//#include <stdlib.h>  
//#include <crtdbg.h> 
//#include "ParticipantRegister.hpp"
//
//void addExerciser(ParticipantRegister& H);
//void addProfessional(ParticipantRegister& H);
//void showParticipant(const ParticipantRegister& H);
//void showProfessional(const ParticipantRegister& H);
//void showExerciser(const ParticipantRegister& H);
//void deleteParticipant(ParticipantRegister& H);
//void changeSeaseon(ParticipantRegister& H);
//void sortAll(ParticipantRegister& H);
//
//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//    int m;
//    ParticipantRegister H;
//    
//    do{
//        cout<<"PARTICIPANTS REGISTER"<<endl;;
//        cout<<"1. Add Exerciser"<<endl;
//        cout<<"2. Add Professional"<<endl;
//        cout<<"3. Display All"<<endl;
//        cout<<"4. Display Exercisers"<<endl;
//        cout<<"5. Display Professionals"<<endl;
//        cout<<"6. Remove Participant"<<endl;
//        cout<<"7. Change Season"<<endl;
//        cout<<"8. Sort Participants"<<endl;
//        cout<<"0. EXIT"<<endl;
//        cout<<"\nEnter digit [0-8]# ";
//        cin >> m;
//        //getchar();
//        
//        switch(m){
//            case 1:
//                addExerciser(H);
//                break;
//                
//            case 2:
//                addProfessional(H);
//                break;
//                
//            case 3:
//                showParticipant(H);
//                break;
//                
//            case 4:
//                showExerciser(H);
//                break;
//                
//            case 5:
//                showProfessional(H);
//                break;
//                
//            case 6:
//                deleteParticipant(H);
//                break;
//                
//            case 7:
//                changeSeaseon(H);
//                break;
//                
//            case 8:
//                sortAll(H);
//                break;
//                
//            default:
//                if(m != 0)
//                    cout<<"\n««ERROR»»\nMust be [0-8]...\n\n";
//                break;
//        }
//    }while(m != 0);
//    
//    return 0;
//}
//void addExerciser(ParticipantRegister& H)
//{
//    int age;
//    string sex, name;
//    
//    cout<<"«««««Add Exerciser»»»»"<<endl;
//    
//    cout<<"Sex: ";
//    cin>>sex;
//    cout<<"Name: ";
//    cin>>name;
//    cout<<"Age: ";
//    cin>>age;
//    
//    H.addExerciser(sex, name, age);
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}
//void addProfessional(ParticipantRegister& H)
//{
//    int seasons;
//    string sex, name, club;
//    
//    cout<<"«««Add Professional»»»"<<endl;
//    
//    cout<<"Sex: ";
//    cin>>sex;
//    cout<<"Name: ";
//    cin>>name;
//    cout<<"Seasons: ";
//    cin>>seasons;
//    cout<<"Club: ";
//    cin>>club;
//    
//    H.addProfessional(sex, name, seasons, club);
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}
//void showParticipant(const ParticipantRegister& H)
//{
//    string *mynewarr = new string[H.getNrOfParticipant()];
//    
//    cout<<"«««««Display All««»»»»"<<endl;
//    
//    H.showParticipant(mynewarr);
//    
//    for(int i = 0; i < H.getNrOfParticipant(); i++)
//        cout<<mynewarr[i]<<endl;
//    
//    delete[] mynewarr;
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}
//void showProfessional(const ParticipantRegister& H)
//{
//    string *mynewarr = new string[H.getNrOfParticipant()];
//    
//    cout<<"«Display Professionals»"<<endl;
//    
//    H.showProfessional(mynewarr);
//    
//    for(int i = 0; i < H.getNrOfProfessional(); i++)
//        cout<<mynewarr[i]<<endl;
//    
//    delete[] mynewarr;
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}
//void showExerciser(const ParticipantRegister& H)
//{
//    string *mynewarr = new string[H.getNrOfParticipant()];
//    
//    cout<<"««Display Exercisers»»"<<endl;
//    
//    H.showExerciser(mynewarr);
//    
//    for(int i = 0; i < H.getNrOfExerciser(); i++)
//        cout<<mynewarr[i]<<endl;
//    
//    delete[] mynewarr;
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}
//void deleteParticipant(ParticipantRegister& H)
//{
//    string name;
//    
//    cout<<"««Remove Participant»»"<<endl;
//
//    cout<<"Enter Name To Search For: ";
//    cin>>name;
//    H.deleteParticipant(name);
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}
//void changeSeaseon(ParticipantRegister& H)
//{
//    int seasons;
//    string name;
//    
//    cout<<"««««Change Season»»»»»"<<endl;
//    
//    cout<<"Enter Name To Search For: ";
//    cin>>name;
//    cout<<"Enter New Amount Of Seasons: ";
//    cin>>seasons;
//    H.changeSeaseon(name, seasons);
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}
//void sortAll(ParticipantRegister& H)
//{
//    string *mynewarr = new string[H.getNrOfParticipant()];
//    
//    cout<<"««Sort Participants»»»"<<endl;
//    
//    H.sortAll();
//    H.showParticipant(mynewarr);
//    
//    for(int i = 0; i < H.getNrOfParticipant(); i++)
//        cout<<mynewarr[i]<<endl;
//    
//    delete[] mynewarr;
//    cout<<"«««««««««««»»»»»»»»»»»"<<endl<<endl;
//}