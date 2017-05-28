//
//  ParticipantRegister.hpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#ifndef ParticipantRegister_hpp
#define ParticipantRegister_hpp

#include "Exercisers.hpp"
#include "Professional.hpp"

class ParticipantRegister
{
private:
    Participant **participants;
    int capacity;
    int nrOfElements;
    
    void expand();
    void freeMemory();
    int findName(string name);
    
public:
    ParticipantRegister();
    ParticipantRegister(const ParticipantRegister &origObj);
    ParticipantRegister &operator=(const ParticipantRegister &origObj);
    ~ParticipantRegister();
    
    bool addExerciser(string sex, string name, int age);
    bool addProfessional(string sex, string name, int seasons, string club);
    bool showParticipant(string string[]) const;
    int getNrOfParticipant() const;
    bool showProfessional(string string[]) const;
    int getNrOfProfessional() const;
    bool showExerciser(string string[]) const;
    int getNrOfExerciser() const;
    bool deleteParticipant(string name);
    bool changeSeaseon(string name, int season);
    bool sortAll() const;
};

#endif /* ParticipantRegister_hpp */
