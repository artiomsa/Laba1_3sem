#pragma once
#include <iostream>
using namespace std;
class Exception2 {};
template <class T>
class LinkedList
{
private:
    template<class T1>
    class Node
    {
    public:
        T1 data;
        Node* pNext;
        Node(T1 data = T1(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int size;
    Node<T>* head;


public:
    LinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    LinkedList(T* items, int count)
    {
        Node<T>* tHead = new Node<T>(items[0]);
        Node<T>* hHead = tHead;
        (this->size)++;
        for (int i = 1; i < count; i++) {
            tHead->pNext = new Node<T>(items[i]);
            tHead = tHead->pNext;
            (this->size)++;
        }
        this->head = hHead;
    }
    LinkedList(LinkedList<T>& list)
    {
        this->head = new Node<T>(list.GetFirst());
        Node<T>* pNode = this->head;
        (this->size)++;
        for (int i = 1; i < list.GetLength(); i++) {
            pNode->pNext = new Node<T>(list.Get(i));
            pNode = pNode->pNext;
            (this->size)++;
        }
    }

    void Append(T item)
    {
        if (this->size < 0) {
            throw new Exception2;
        }
        Node<T>* pTek = new Node<T>(item);
        pTek->pNext = this->head;
        this->head = pTek;
        (this->size)++;
    }
    void Prepend(T item)
    {
        if (this->size < 0) {
            throw new Exception2;
        }
        Node<T>* pTek;
        pTek = this->head;
        if (this->head == nullptr) {
            this->Append(item);
            pTek = this->head;
        }
        else
        {
            while (pTek->pNext != nullptr) {
                pTek = pTek->pNext;
            }
            pTek->pNext = new Node<T>(item);
            (this->size)++;
        }

    }
    void Set(int index, T item)
    {
        Node<T>* tek = this->head;
        for(int i = 0; i<index;i++)
        {
            tek = tek->pNext;
        }
        tek->data = item;
    }
    T Get(int index)
    {
        int count = 0;
        Node<T>* pTek;
        pTek = this->head;
        while (true) {
            if (count == index) {
                return pTek->data;
            }
            pTek = pTek->pNext;
            count++;
        }
    }

    T GetFirst()
    {
        if (this->size <= 0) {
            throw new Exception2;
        }
        Node<T>* pTek;
        pTek = this->head;
        return pTek->data;
    }

    T GetLast()
    {
        if (this->size <= 0) {
            throw new Exception2;
        }
        Node<T>* pTek;
        pTek = this->head;
        for (int i = 0; i < this->size - 1; i++) {
            pTek = pTek->pNext;
        }
        return pTek->data;

    }

    int GetLength()
    {
        return this->size;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        LinkedList<T>* newList = new LinkedList();
        for (int i = startIndex; i <= endIndex; i++) {
            newList->Prepend(this->Get(i));
        }
        return newList;
    }

    void InsertAt(T item, int index)
    {
        int count = 0;
        Node<T>* pTek = this->head;
        if (index < 0 || index >= this->size) {
            throw new Exception2;
        }
        if (index == 0)
        {
            this->Append(item);
            //break;
        }
        else
        {
            while (true) {
                if (count == index - 1) {
                    Node<T>* pNode = pTek->pNext;
                    pTek->pNext = new Node<T>(item);
                    pTek->pNext->pNext = pNode;
                    (this->size)++;
                    break;
                }
                count++;
                pTek = pTek->pNext;
            }
        }
    }

    LinkedList<T>* Concat(LinkedList<T>* list)
    {
        LinkedList<T>* newList = new LinkedList();
        for (int i = 0; i < this->GetLength(); i++) {
            newList->Prepend(this->Get(i));
        }
        for (int i = 0; i < list->GetLength(); i++) {
            newList->Prepend(list->Get(i));
        }
        return newList;
    }
    void reverse( Node<T>* current, Node<T>* cur_next)
    {
        if(cur_next->pNext != nullptr)
        {
            reverse(cur_next,cur_next->pNext);
        }
        cur_next->pNext = current;
    }
    void Reverse()
    {
        if(this->size == 1)
            return;
        Node<T>* new_head = this->head;
        for(int i = 0; i < this->GetLength();i++)
        {
            if(new_head->pNext != nullptr)
                new_head = new_head->pNext;
        }
        Node<T>* current;
        Node<T>* cur_next;
        current = this->head;
        cur_next = this->head->pNext;
        this->head->pNext = nullptr;
        reverse(current, cur_next);
        this->head = new_head;
    }
    void Delete(bool(*comp)(const T& temp))
    {
        while(this->size != 1)
        {
            if(comp(this->head->data))
            {
                this->head = this->head->pNext;
                this->size--;
                continue;
            }
            Node<T>* tek = this->head;
            Node<T>* pred = this->head;
            while(!comp(tek->data) && tek->pNext != nullptr)
            {
                pred = tek;
                tek = tek->pNext;
            }
            if(tek->pNext == nullptr && comp(tek->data))
            {
                pred->pNext = tek->pNext;
                this->size--;
                return;
            }
            if(tek->pNext == nullptr && !comp(tek->data))
            {
                return;
            }
            pred->pNext = tek->pNext;
            delete tek;
            this->size--;
        }
    }

};