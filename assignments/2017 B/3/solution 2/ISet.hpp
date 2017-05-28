//
//  ISet.h
//  Uppgift C 2
//
//  Created by Marcus Lenander on 2017-04-02.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

#ifndef ISet_hpp
#define ISet_hpp

template <typename T>
class ISet
{
public:
    virtual bool insert(T element) = 0;
    virtual bool remove(T element) throw(...) = 0;
    virtual int size() const = 0;
};

#endif /* ISet_hpp */
