#pragma once
#include <iostream>
#include "Sequence.hpp"
#include "LinkedList.hpp"
template <class T>
class LinkedListSequence : public Sequence<T>
{
private:
    int size;
    LinkedList<T>* list;
public:
    LinkedListSequence()
    {
        this->list = new LinkedList<T>();
    }
    LinkedListSequence(T* items, int count)
    {
        this->list = new LinkedList<T>(items, count);
    }
    LinkedListSequence(LinkedList<T>& list)
    {
        this->list = new LinkedList<T>(list);
    }
    T GetFirst() override
    {
        return this->list->GetFirst();
    }
    T GetLast() override
    {
        return this->list->GetLast();
    }
    T Get(int index) override
    {
        return this->list->Get(index);
    }
    void Set(T item, int index) override
    {
        this->list->Set(index,item);
    }
    int GetLength() override
    {
        return this->list->GetLength();
    }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        LinkedList<T>* pList = (this->list->GetSubList(startIndex, endIndex));
        LinkedList<T>& Link = *pList;
        LinkedList<T> list(Link);
        Sequence<T>* newSeq = new LinkedListSequence(list);
        return newSeq;

    }
    void Append(T item) override
    {
        this->list->Append(item);
    }
    void Prepend(T item) override
    {
        this->list->Prepend(item);
    }
    void InsertAt(T item, int index) override
    {
        this->list->InsertAt(item, index);
    }
    Sequence<T>* Concat(Sequence<T>* list) override
    {
        T* arr = new T[this->GetLength() + list->GetLength()];
        for (int i = 0; i < this->GetLength(); i++)
        {
            arr[i] = this->Get(i);
        }
        for (int i = 0; i < list->GetLength(); i++)
        {
            arr[i+ this->GetLength()] = list->Get(i);
        }
        Sequence<T>* newSeq = new LinkedListSequence(arr, this->GetLength() + list->GetLength());
        return newSeq;
    }


};