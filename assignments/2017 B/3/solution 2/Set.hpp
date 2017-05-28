//
//  Set.h
//  Uppgift C 2
//
//  Created by Marcus Lenander on 2017-04-02.
//  Copyright © 2017 Marcus Lenander. All rights reserved.
//

/*
 **Testar tilldelningsoperator: Ej korrekt, du testar tilldelningsoperatorn två gånger istället
 
 *??Tilldelningsoperator är korrekt: Ej korrekt, fungerar inte som den ska, du ska inte göra new i
 din loop, det är bara en enkelpekare du använder

 **Kopieringskonstruktor är korrekt: Ej korrekt, du ska inte göra new i din loop, det är bara en
 enkelpekare du använder
 
 **Undantag från remove hanteras korrekt: Ej korrekt, du ska bara throwa om mängden är
 tom
 
 **alla funktioner som kan vara const är det: Ej korrekt, findElement är inte const
 
 */

#ifndef Set_hpp
#define Set_hpp


#include "ISet.hpp"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Set : public ISet<T>
{
private:
    T *setArray;
    int capacity;
    int nrOfElements;
    int findElement(T element) const;
    void expand();
    
public:
    Set();
    Set(int capacity);
    Set(const Set &origObj);
    Set &operator=(const Set &origObj);
    ~Set();

    bool insert(T element);
    bool remove(T element) throw(...);
    int size() const;
};
template <typename T>
Set<T>::Set()
{
    this->capacity = 0;
    this->nrOfElements = 0;
}
template <typename T>
Set<T>::Set(int capacity)
{
    this->capacity = capacity;
    this->nrOfElements = 0;
    setArray = new T[capacity];
}
template <typename T>
Set<T>::Set(const Set &origObj)
{
    this->capacity = origObj.capacity;
    this->nrOfElements = origObj.nrOfElements;
    setArray = new T[origObj.capacity];

    for(int i = 0; i < origObj.capacity; i ++)
        setArray[i] = T(origObj.setArray[i]);
}
template <typename T>
Set<T> &Set<T>::operator=(const Set &origObj)
{
    if(*this != &origObj)
    {
        delete[] setArray;
        this->capacity = origObj.capacity;
        this->nrOfElements = origObj.nrOfElements;
        setArray = new T[origObj.capacity];
        
        for(int i = 0; i < origObj.capacity; i ++)
            setArray[i] = T(origObj.setArray[i]);
    }
    return *this;
}
template <typename T>
Set<T>::~Set()
{
    delete[] setArray;
}
template <typename T>
int Set<T>::findElement(T element) const
{
    int pos = -1;
    
    for(int i = 0; i < this->nrOfElements; i++)
    {
        if(setArray[i] == element)
            pos = i;
    }
    return pos;
}
template <typename T>
void Set<T>::expand()
{
    T* tempArr = new T[this->capacity+1];
    
    for(int i=0; i < this->capacity; i++)
        tempArr[i] = setArray[i];
    
    delete[] setArray;
    setArray = tempArr;
    capacity++;
}
template <typename T>
bool Set<T>::insert(T element)
{
    int pos = findElement(element);
    bool index = false;
    
    if(nrOfElements == capacity)
        expand();
    
    if(pos == -1)
    {
        setArray[nrOfElements] = element;
        nrOfElements += 1;
        index = true;
    }
    return index;
}
template <typename T>
bool Set<T>::remove(T element) throw(...)
{
    int pos = findElement(element);
    bool index = false;
    
    if(pos != -1)
    {
        nrOfElements--;
        index = true;
        
        for(int i = pos; i < nrOfElements; i++)
            setArray[i] = setArray[i+1];
    }
    else if(nrOfElements == 0)
        throw "Cant remove on empty list";
    
    return index;
}
template <typename T>
int Set<T>::size() const
{
    return this->nrOfElements;
}

#endif /* Set_hpp */
