#pragma once
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
using namespace std;
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
    Numbers(Numbers<T>* num)
    {
        this->size = num->GetLength();
        this->items = new ArraySequence<T>(this->size);
        for(int i = 0; i < this->GetLength(); i++)
        {
            this->items->Set(num->Get(i),i);
        }
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
class Animal
{
public:
    int age;
    string name;
    int height;
    Animal(){}
    Animal(int age, string name, int height)
    {
        this->age = age;
        this->name = name;
        this->height = height;
    }
    //virtual void Say() = 0;

};
class Cat: public Animal
{
public:
    Cat(){}
    Cat(int age, string name, int height)
    {
        this->age = age;
        this->name = name;
        this->height = height;
    }
//    virtual void Say() override
//    {
//        cout << "kjwebfkj";
//    }
};
class Dog: public Animal
{
public:
    Dog(){}
    Dog(int age, string name, int height)
    {
        this->age = age;
        this->name = name;
        this->height = height;
    }
//    virtual void Say() override
//    {
//        cout << "WWWWWW";
//    }
};
