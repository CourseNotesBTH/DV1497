//
//  Professional.cpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#include "Professional.hpp"

Professional::Professional()
{
    this->seasons = 0;
    this->club = "?";
}
Professional::Professional(string sex, string name, int seasons, string club)
: Participant(sex, name)
{
    this->seasons = seasons;
    this->club = club;
}
Professional::Professional(const Professional &origObj)
{
    this->setSex(origObj.getSex());
    this->setName(origObj.getName());
    this->seasons = origObj.seasons;
    this->club = origObj.club;
}
Professional &Professional::operator=(const Professional &origObj)
{
    if(this != &origObj)
    {
        this->setSex(origObj.getSex());
        this->setName(origObj.getName());
        this->seasons = origObj.seasons;
        this->club = origObj.club;
    }
    return *this;
}
Professional::~Professional()
{
}
int Professional::getSeason() const
{
    return this->seasons;
}
string Professional::getClub() const
{
    return this->club;
}
void Professional::setSeason(int seasons)
{
    this->seasons = seasons;
}
void Professional::setClub(string club)
{
    this->club = club;
}
Professional *Professional::clone() const
{
    return new Professional(*this);
}
string Professional::toStringSpecific() const
{
    return this->club + "\n" + to_string(this->seasons) + "\n";
}