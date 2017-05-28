//
//  ParticipantRegister.cpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "ParticipantRegister.hpp"

ParticipantRegister::ParticipantRegister()
{
    this->capacity = 0;
    this->nrOfElements = 0;
    this->participants = new Participant*[capacity];
}
ParticipantRegister::ParticipantRegister(const ParticipantRegister &origObj)
{
    this->capacity = origObj.capacity;
    this->nrOfElements = origObj.nrOfElements;
    this->participants = new Participant*[origObj.capacity];
    
    for(int i = 0; i < origObj.nrOfElements; i++)
        this->participants[i] = origObj.participants[i]->clone();
}
ParticipantRegister &ParticipantRegister::operator=(const ParticipantRegister &origObj)
{
    if(this != &origObj)
    {
        this->freeMemory();
        this->capacity = origObj.capacity;
        this->nrOfElements = origObj.nrOfElements;
        this->participants = new Participant*[origObj.capacity];
        
		for (int i = 0; i < origObj.nrOfElements; i++)
			this->participants[i] = origObj.participants[i]->clone();
    }
    return *this;
}
ParticipantRegister::~ParticipantRegister()
{
    this->freeMemory();
}
void ParticipantRegister::expand()
{
    Participant** tempParticipant = new Participant*[this->capacity + 1];
    
    for(int i=0; i < this->capacity; i++)
        tempParticipant[i] = participants[i];
    
    delete[] this->participants;
    this->participants = tempParticipant;
    this->capacity += 1;
}
void ParticipantRegister::freeMemory()
{
    for(int i=0; i < this->nrOfElements; i++)
        delete this->participants[i];
    
    delete[] this->participants;
}
int ParticipantRegister::findName(string name)
{
    int pos = -1;
    
    for(int i=0; i < this->nrOfElements; i++){
        if(this->participants[i]->getName() == name)
            pos = i;
    }
    return pos;
}
bool ParticipantRegister::addExerciser(string sex, string name, int age)
{
    bool add = false;
    
    if(this->findName(name) == -1)
    {
        if(this->nrOfElements == this->capacity)
            this->expand();
        
        this->participants[this->nrOfElements] = new Exercisers(sex, name, age);
        this->nrOfElements++;
        add = true;
    }
    return add;
}
bool ParticipantRegister::addProfessional(string sex, string name, int seasons, string club)
{
    bool index = false;
    
    if(this->findName(name) == -1)
    {
        if(this->nrOfElements == this->capacity)
            this->expand();
        
        this->participants[this->nrOfElements] = new Professional(sex, name, seasons, club);
        this->nrOfElements++;
        index = true;
    }
    return index;
}
bool ParticipantRegister::showParticipant(string string[]) const
{
    bool index = false;
    
    if(nrOfElements > 0)
    {
        for(int i = 0; i < this->nrOfElements; i++)
            string[i] = this->participants[i]->toString();
    
        index = true;
    }
    return index;
}
int ParticipantRegister::getNrOfParticipant() const
{
    return this->nrOfElements;
}
bool ParticipantRegister::showProfessional(string string[]) const
{
    bool index = false;
    int j=0;
    
    for(int i=0; i < this->nrOfElements; i++)
    {
        if(dynamic_cast<Professional*>(this->participants[i]))
        {
            string[j] = this->participants[i]->toString();
            index = true;
            j++;
        }
    }
    return index;
}
int ParticipantRegister::getNrOfProfessional() const
{
    int nrOfProfessional = 0;
    
    for(int i=0; i < this->nrOfElements; i++)
    {
        if(dynamic_cast<Professional*>(this->participants[i]))
            nrOfProfessional++;
    }
    return nrOfProfessional;
}
bool ParticipantRegister::showExerciser(string string[]) const
{
    bool index = false;
    int j=0;
    
    for(int i=0; i < this->nrOfElements; i++)
    {
        if(dynamic_cast<Exercisers*>(this->participants[i]))
        {
            string[j] = this->participants[i]->toString();
            index = true;
            j++;
        }
    }
    return index;
}
int ParticipantRegister::getNrOfExerciser() const
{
    int nrOfExerciser = 0;
    
    for(int i=0; i < this->nrOfElements; i++)
    {
        if(dynamic_cast<Exercisers*>(this->participants[i]))
            nrOfExerciser++;
    }
    return nrOfExerciser;
}
bool ParticipantRegister::deleteParticipant(string name)
{
    bool index = false;
    int pos = findName(name);
    
    if(pos != -1)
    {
        delete this->participants[pos];
        this->nrOfElements--;
            
        for(int j = pos; j < this->nrOfElements; j++)
            participants[j] = participants[j+1];
        index = true;
    }
    return index;
}
bool ParticipantRegister::changeSeaseon(string name, int season)
{
    bool index = false;
    Professional *aProPtr = nullptr;
    int nr = findName(name);
    
    if(nr != -1)
    {
        if(dynamic_cast<Professional*>(this->participants[nr]))
        {
            aProPtr = dynamic_cast<Professional*>(participants[nr]);
            aProPtr->setSeason(season);
            index = true;
        }
    }
    return index;
}
bool ParticipantRegister::sortAll() const
{
    bool index = false;
    int minIndex = 0;
    Participant *temp;
    
    if(nrOfElements > 0)
    {
        for(int i=0; i < nrOfElements-1; i++)
        {
            minIndex = i;
        
            for(int k=i+1; k < nrOfElements; k++)
            {
                if(participants[k]->getName() < participants[minIndex]->getName())
                {
                    minIndex = k;
                }
            }
            temp = participants[i];
            participants[i] = participants[minIndex];
            participants[minIndex] = temp;
            index = true;
        }
    }
    return index;
}