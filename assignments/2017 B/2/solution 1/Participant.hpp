//
//  Participant.hpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#ifndef Participant_hpp
#define Participant_hpp

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Participant
{
private:
    string sex;
    string name;
    
public:
    Participant();
    Participant(string sex, string name);
    Participant(const Participant &origObj);
    Participant &operator=(const Participant &origObj);
    virtual ~Participant() = 0;
    
    string getSex() const;
    string getName() const;
    void setSex(string sex);
    void setName(string name);
    
    virtual Participant* clone() const = 0;
    string toString()const;
    virtual string toStringSpecific() const = 0;
};

#endif /* Participant_hpp */
