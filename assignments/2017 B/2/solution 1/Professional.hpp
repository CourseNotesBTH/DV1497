//
//  Professional.hpp
//  TävlingsDeltagare
//
//  Created by Marcus Lenander on 2017-03-29.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#ifndef Professional_hpp
#define Professional_hpp

#include "Participant.hpp"

class Professional : public Participant
{
private:
    int seasons;
    string club;
public:
    Professional();
    Professional(string sex, string name, int seasons, string club);
    Professional(const Professional &origObj);
    Professional &operator=(const Professional &origObj);
    ~Professional();
    
    int getSeason() const;
    string getClub() const;
    void setSeason(int seasons);
    void setClub(string club);
    
    Professional *clone() const;
    string toStringSpecific() const;
};

#endif /* Professional_hpp */
