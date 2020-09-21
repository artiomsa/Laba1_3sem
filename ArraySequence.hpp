#pragma once
#include <iostream>
#include "Sequence.hpp"
#include "DynamicArray.hpp"
template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;
    int size;
public:
    ArraySequence()
    {
        this->items = new DynamicArray<T>(0);
    }
    ArraySequence(T* items, int count)
    {
        this->items = new DynamicArray<T>(items,count);
    }
    ArraySequence(DynamicArray<T>& array)
    {
        this->items = new DynamicArray<T>(array);

    }
    ArraySequence(int size)
    {
        this->items = new DynamicArray<T>(size);
    }
    T GetFirst() override
    {
        return this->items->Get(0);
    }
    T GetLast() override
    {
        return this->items->Get(this->items->GetSize() -1);
    }
    T Get(int index) override
    {
        return this->items->Get(index);
    }
    int GetLength() override
    {
        return this->items->GetSize();
    }
    void Set(T item, int index)override
    {
        this->items->Set(index,item);
    }
    void InsertAt(T item, int index)override
    {
        DynamicArray<T>* newArray = new DynamicArray<T>((this->items->GetSize()) + 1);
        for (int i = 0; i < index; i++)
        {
            newArray->Set(i, this->items->Get(i));
        }
        newArray->Set(index, item);
        for (int i = index+1; i < newArray->GetSize(); i++)
        {
            newArray->Set(i, this->items->Get(i-1));
        }
        this->items = newArray;
    }
    void Append(T item)override
    {
        DynamicArray<T>* newArray = new DynamicArray<T>((this->items->GetSize())+1);
        for (int i = 1; i < newArray->GetSize(); i++)
        {
            newArray->Set(i, this->items->Get(i - 1));
        }
        newArray->Set(0, item);
        this->items = newArray;
    }
    void Prepend(T item)override {
        DynamicArray<T>* newArray = new DynamicArray<T>((this->items->GetSize()) + 1);
        for (int i = 0; i < this->items->GetSize(); i++)
        {
            newArray->Set(i, this->items->Get(i));
        }
        newArray->Set(newArray->GetSize() - 1, item);
        this->items = newArray;
    }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        T* arr = new T[endIndex - startIndex + 1];
        for (int i = 0; i <= endIndex - startIndex + 1; i++)
        {
            arr[i] = this->items->Get(i+ startIndex);
        }
        Sequence<T>* newSeq = new ArraySequence<T>(arr, endIndex - startIndex + 1);
        return newSeq;
    }
    Sequence<T>* Concat(Sequence<T>* array)override
    {
        T* newArray = new T[this->GetLength() + array->GetLength()];
        for (int i = 0; i < this->GetLength(); i++)
        {
            newArray[i] = this->Get(i);
        }
        for (int i = 0; i < array->GetLength(); i++)
        {
            newArray[i + this->GetLength()] = array->Get(i);
        }
        Sequence<T>* newSeq = new ArraySequence<T>(newArray, this->GetLength() + array->GetLength());
        return newSeq;
    }
};
