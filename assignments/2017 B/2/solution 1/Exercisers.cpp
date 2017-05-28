//
//  Exercisers.cpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "Exercisers.hpp"

Exercisers::Exercisers()
{
    this->age = 0;
}
Exercisers::Exercisers(string sex, string name, int age)
:Participant(sex, name)
{
    this->age = age;
}
Exercisers::Exercisers(const Exercisers &origObj)
{
    this->setSex(origObj.getSex());
    this->setName(origObj.getName());
    this->age = origObj.age;
}
Exercisers &Exercisers::operator=(const Exercisers &origObj)
{
    if(this != &origObj)
    {
        this->setSex(origObj.getSex());
        this->setName(origObj.getName());
        this->age = origObj.age;
    }
    return *this;
}
Exercisers::~Exercisers()
{
}
int Exercisers::getAge() const
{
    return this->age;
}
void Exercisers::setAge(int age)
{
    this->age = age;
}
Exercisers *Exercisers::clone() const
{
    return new Exercisers(*this);
}
string Exercisers::toStringSpecific() const
{
    return to_string(this->age) + "\n";
}