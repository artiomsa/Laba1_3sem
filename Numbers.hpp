#pragma once
#include "Sequence.hpp"
template<class T>
class Numbers
{
private:
    int size;
    Sequence<T>* items;
public:
    Numbers()
    {
        this->size = 0;
        this->items = nullptr;
    }
    Numbers(Sequence<T>* items)
    {
        this->size = items->GetLength();
        this->items = items;
    }
    int GetLength()
    {
        return this->size;
    }
    T Get(int index)
    {
        return this->items->Get(index);
    }
    void Set(T item, int index)
    {
        this->items->Set(item,index);
    }

};