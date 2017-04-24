//
//  Set.hpp
//  Inlämning C 2
//
//  Created by Alex Gustafsson on 2017-04-01.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#ifndef Set_hpp
#define Set_hpp

template<typename T>
class Set {
private:
    T* elements;
    int capacity;
    int count;
    void expand();
    int indexOf(T element) const;
public:
    Set();
    Set(const Set& other);
    ~Set();
    
    Set& operator = (const Set other);
    bool operator == (const Set& other) const;
    bool operator != (const Set& other) const;
    
    bool insert(T element);
    bool remove(T element) throw(...);
    
    int size() const;
};

template<typename T>
Set<T>::Set(){
    this->capacity = 0;
    this->count = 0;
}

template<typename T>
Set<T>::Set(const Set& other){
    this->capacity = other.capacity;
    this->count = other.count;
    
    this->elements = new T[other.capacity];
    for(int i = 0; i < other.count; i++)
        this->elements[i] = other.elements[i];
}

template<typename T>
Set<T>::~Set(){
    delete[] this->elements;
}

template<typename T>
Set<T>& Set<T>::operator = (const Set other){
    if(*this != other){
        delete[] this->elements;
        
        this->capacity = other.capacity;
        this->count = other.count;
        
        this->elements = new T[other.capacity];
        for(int i = 0; i < other.count; i++)
            this->elements[i] = other.elements[i];
    }
    
    //convention
    return *this;
}

template<typename T>
bool Set<T>::operator == (const Set& other) const{
    bool matching = false;
    
    // Compare count and capacity, then compare each element
    if(this->count == other.count && this->capacity == other.capacity){
        // Note O(n^2), could probably be better using hash tables or something similar
        for(int i = 0; i < this->count; i++){
            bool matchedElement = false;
            for(int j = 0; j < other.count; j++){
                if(this->elements[i] == other.elements[j]){
                    matchedElement = true;
                    break;
                }
            }
            
            if(matchedElement){
                matching = true;
            } else {
                // Don't continue to compare if a mismatch has already been found
                break;
            }
        }
    }
    
    return matching;
}

template<typename T>
bool Set<T>::operator != (const Set& other) const{
    return !(*this == other);
}

template<typename T>
void Set<T>::expand(){
    if(this->count + 1 > this->capacity){
        T* temp = new T[this->capacity + 1];
        for(int i = 0; i < this->count; i++)
            temp[i] = this->elements[i];
        
        delete[] this->elements;
        
        this->elements = temp;
    }
}

template<typename T>
int Set<T>::indexOf(T element) const {
    int index = -1;
    for(int i = 0; i < this->count; i++){
        if(this->elements[i] == element){
            index = i;
            break;
        }
    }
    
    return index;
}

template<typename T>
bool Set<T>::insert(T element) {
    if(this->indexOf(element) == -1){
        this->expand();
        this->elements[this->count] = element;
        this->count++;
        
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool Set<T>::remove(T element) throw(...){
    if(this->count == 0)
        throw("Set is empty");
    
    int index = this->indexOf(element);
    
    if(index != -1) {
        for(int i = index; i < this->count - 1; i++)
            this->elements[i] = this->elements[i + 1];
        this->count--;
        
        return true;
    } else {
        return false;
    }
}

template<typename T>
int Set<T>::size() const{
    return this->count;
}

#endif /* Set_hpp */
