#ifndef ISET_H
#define ISET_H

template <typename T>
class ISet
{
public:
    virtual bool insert(T element) = 0;
    virtual bool remove(T element)throw(...) = 0;
    virtual int size() const = 0;
};

#endif
