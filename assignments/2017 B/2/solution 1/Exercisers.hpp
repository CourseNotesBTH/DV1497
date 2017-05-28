//
//  Exercisers.hpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#ifndef Exercisers_hpp
#define Exercisers_hpp

#include "Participant.hpp"

class Exercisers : public Participant
{
private:
    int age;
    
public:
    Exercisers();
    Exercisers(string sex, string name, int age);
    Exercisers(const Exercisers &origObj);
    Exercisers &operator=(const Exercisers &origObj);
    ~Exercisers();
    
    int getAge() const;
    void setAge(int age);
    
    Exercisers *clone() const;
    string toStringSpecific() const;
    
};




#endif /* Exercisers_hpp */
