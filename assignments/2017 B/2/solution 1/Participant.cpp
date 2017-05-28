//
//  Participant.cpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "Participant.hpp"

Participant::Participant()
{
    this->sex = "?";
    this->name = "?";
}
Participant::Participant(string sex, string name)
{
    this->sex = sex;
    this->name = name;
}
Participant::Participant(const Participant &origObj)
{
    this->sex = origObj.sex;
    this->name = origObj.name;
}
Participant &Participant::operator=(const Participant &origObj)
{
    if(this != &origObj)
    {
        this->sex = origObj.sex;
        this->name = origObj.name;
    }
    return *this;
}
Participant::~Participant()
{
}
string Participant::getSex() const
{
    return this->sex;
}
string Participant::getName() const
{
    return this->name;
}
void Participant::setSex(string sex)
{
    this->sex = sex;
}
void Participant::setName(string name)
{
    this->name = name;
}
string Participant::toString() const
{
    return this->sex + "\n" + this->name + "\n" + toStringSpecific();
}