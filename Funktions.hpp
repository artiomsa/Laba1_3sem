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

void SortBubble(Numbers<int>* num)
{
    unsigned int start = clock();
    int w = 1;
    bool check = false;
    for(int i = 0; i < num->GetLength()-1;i++)
    {
        for(int j = 0; j<num->GetLength()-w;j++)
        {
            if(num->Get(j)>num->Get(j+1))
            {
                int k = num->Get(j);
                int kk = num->Get(j+1);
                num->Set(k,j+1);
                num->Set(kk,j);
                check = true;
            }
        }
        if (check == false)
        {
            unsigned int stop = clock();
            cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
        check = false;
        w++;
    }
    unsigned int stop = clock();
    cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}
void SortBubble(Numbers<double>* num)
{
    unsigned int start = clock();
    int w = 1;
    bool check = false;
    for(int i = 0; i < num->GetLength()-1;i++)
    {
        for(int j = 0; j<num->GetLength()-w;j++)
        {
            if(num->Get(j)>num->Get(j+1))
            {
                double k = num->Get(j);
                double kk = num->Get(j+1);
                num->Set(k,j+1);
                num->Set(kk,j);
                check = true;
            }
        }
        if (check == false)
        {
            unsigned int stop = clock();
            cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
        check = false;
        w++;
    }
    unsigned int stop = clock();
    cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}

void SortBubbleShake(Numbers<int>* num)
{
    unsigned int start = clock();
    int left = 0;
    int right = num->GetLength();
    bool check = false;
    while(check == false)
    {
        for(int j = 0; j < right-1;j++)
        {
            if(num->Get(j) > num->Get(j+1))
            {
                int k = num->Get(j);
                int kk = num->Get(j+1);
                num->Set(kk,j);
                num->Set(k,j+1);
                check = true;
            }
        }
        right--;
        for(int j = right-1;j>left+1;j--)
        {
            if(num->Get(j-1)>num->Get(j))
            {
                int k = num->Get(j);
                int kk = num->Get(j-1);
                num->Set(kk,j);
                num->Set(k,j-1);
                check = true;
            }
        }
        left++;
        if(check == false)
        {
            unsigned int stop = clock();
            cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
        if(check == true)
        {
            check = false;
        }
        if(left == right)
        {
            unsigned int stop = clock();
            cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
    }

}
void SortBubbleShake(Numbers<double>* num)
{
    unsigned int start = clock();
    int left = 0;
    int right = num->GetLength();
    bool check = false;
    while(check == false)
    {
        for(int j = 0; j < right-1;j++)
        {
            if(num->Get(j) > num->Get(j+1))
            {
                double k = num->Get(j);
                double kk = num->Get(j+1);
                num->Set(kk,j);
                num->Set(k,j+1);
                check = true;
            }
        }
        right--;
        for(int j = right-1;j>left+1;j--)
        {
            if(num->Get(j-1)>num->Get(j))
            {
                double k = num->Get(j);
                double kk = num->Get(j-1);
                num->Set(kk,j);
                num->Set(k,j-1);
                check = true;
            }
        }
        left++;
        if(check == false)
        {
            unsigned int stop = clock();
            cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
        if(check == true)
        {
            check = false;
        }
        if(left == right)
        {
            unsigned int stop = clock();
            cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
    }

}

void SortCount(Numbers<int>* num)
{
    unsigned int start = clock();
    int min = 1000;
    int max = -1000;
    for(int i = 0; i < num->GetLength(); i++)
    {
        if(num->Get(i)>max)
            max = num->Get(i);
        if(num->Get(i)<min)
            min = num->Get(i);
    }

    Sequence<int>* count = new ArraySequence<int>();
    for(int i = 0; i < max - min + 1; i ++)
    {
        count->Prepend(0);
    }

    for(int i = 0; i < num->GetLength();i++)
    {
        count->Set(count->Get(num->Get(i) - min)+1,num->Get(i) - min);
    }

    int j = 0;
    for(int i = 0; i < num->GetLength();i++)
    {
        if(count->Get(j) == 0)
        {
            j++;
            i--;
        }
        else if(count->Get(j) != 0)
        {
            num->Set((min + j),i);
            count->Set((count->Get(j)-1),j);
        }

    }
    unsigned int stop = clock();
    cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}
void SortCount(Numbers<double>* num)
{
    unsigned int start = clock();
    double min = 1000;
    double max = -1000;
    for(int i = 0; i < num->GetLength(); i++)
    {
        if(num->Get(i)>max)
            max = num->Get(i);
        if(num->Get(i)<min)
            min = num->Get(i);
    }

    Sequence<double>* count = new ArraySequence<double>();
    for(int i = 0; i < max - min + 1; i ++)
    {
        count->Prepend(0);
    }

    for(int i = 0; i < num->GetLength();i++)
    {
        count->Set(count->Get(num->Get(i) - min)+1,num->Get(i) - min);
    }

    int j = 0;
    for(int i = 0; i < num->GetLength();i++)
    {
        if(count->Get(j) == 0)
        {
            j++;
            i--;
        }
        else if(count->Get(j) != 0)
        {
            num->Set((min + j),i);
            count->Set((count->Get(j)-1),j);
        }

    }
    unsigned int stop = clock();
    cout << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
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