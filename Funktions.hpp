#pragma once
#include "Numbers.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include <ctime>
#include <stdio.h>
using namespace std;
Numbers<int>* FillNumbersArrayInt(int count)
{
    Sequence<int>* items = new ArraySequence<int>();
    int item;
    for(int i = 0; i < count; i++)
    {
        cin >> item;
        items->Prepend(item);
    }
    Numbers<int>* num = new Numbers<int>(items);
    return num;
}
Numbers<double>* FillNumbersArrayDouble(int count)
{
    Sequence<double>* items = new ArraySequence<double>();
    double item;
    for(int i = 0; i< count; i++)
    {
        cin >> item;
        items->Prepend(item);
    }
    Numbers<double>* num = new Numbers<double>(items);
    return num;
}
Numbers<int>* FillNumbersListInt(int count)
{
    Sequence<int>* items = new LinkedListSequence<int>();
    int item;
    for(int i = 0; i < count;i++)
    {
        cin >> item;
        items->Prepend(item);
    }
    Numbers<int>* num = new Numbers<int>(items);
    return num;
}
Numbers<double>* FillNumbersListDouble(int count)
{
    Sequence<double>* items = new LinkedListSequence<double>();
    double item;
    for(int i = 0; i < count;i++)
    {
        cin >> item;
        items->Prepend(item);
    }
    Numbers<double>* num = new Numbers<double>(items);
    return num;
}

template<class T>
bool comp1(const T& a, const T& b)
{
    return a > b;
}
bool comp2(const Animal& a, const Animal& b)
{
    return a.age > b.age;
}
bool compPointer(Animal* a, Animal* b)
{
    return a->age < b->age;
}
bool compCount(const Animal& a,const Animal& b)
{
    return a.age > b.age;
}
void PrintNumbers(Numbers<int>* num)
{
    for(int i = 0; i < num->GetLength();i++)
    {
        cout << num->Get(i) << " ";
    }
    cout<<""<<endl;
}
void PrintNumbers(Numbers<double>* num)
{
    for(int i = 0; i < num->GetLength();i++)
    {
        cout << num->Get(i) << " ";
    }
    cout<<""<<endl;
}
void PrintAnimal(Animal animal)
{
    cout << animal.name<<" ";
    cout << animal.age<<" ";
    cout << animal.height<<endl;
}

Numbers<double>* FillNumRandDoubleArray(int count)
{
    Sequence<double>* items = new ArraySequence<double>();
    for(int i = 0;i < count; i++)
    {
        items->Prepend((1 + rand() % 300) + 0.1);
    }
    Numbers<double>* res = new Numbers<double>(items);
    return res;
}
Numbers<int>* FillNumRandIntArray(int count)
{
    Sequence<int>* items = new ArraySequence<int>();
    for(int i = 0;i < count; i++)
    {
        items->Prepend((1 + rand() % 300));
    }
    Numbers<int>* res = new Numbers<int>(items);
    return res;
}
Numbers<int>* FillNumRandIntList(int count)
{
    Sequence<int>* items = new LinkedListSequence<int>();
    for(int i = 0; i < count;i++)
    {
        items->Prepend((1 + rand() % 300));
    }
    Numbers<int> * num = new Numbers<int>(items);
    return num;
}
Numbers<double>* FillNumRandDoubleList(int count)
{
    Sequence<double>* items = new LinkedListSequence<double>();
    for(int i = 0; i < count;i++)
    {
        items->Prepend((1 + rand() % 300) + 0.1);
    }
    Numbers<double> * num = new Numbers<double>(items);
    return num;
}
