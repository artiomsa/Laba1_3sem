#pragma once
#include "Sequence.hpp"
#include "Funktions.hpp"
void Tests() {
    Numbers<double>* n10 = FillNumRandDoubleArray(7000);
    Numbers<int>* n11 = FillNumRandIntArray(7000);
    Numbers<int>* n12 = FillNumRandIntList(7000);
    Numbers<double>* n13 = FillNumRandDoubleList(7000);

    Numbers<double>* n20 = FillNumRandDoubleArray(7000);
    Numbers<int>* n21 = FillNumRandIntArray(7000);
    Numbers<int>* n22 = FillNumRandIntList(7000);
    Numbers<double>* n23 = FillNumRandDoubleList(7000);

    Numbers<double>* n30 = FillNumRandDoubleArray(7000);
    Numbers<int>* n31 = FillNumRandIntArray(7000);
    Numbers<int>* n32 = FillNumRandIntList(7000);
    Numbers<double>* n33 = FillNumRandDoubleList(7000);


    SortBubble(n10);
    SortBubble(n11);
    SortBubble(n12);
    SortBubble(n13);

    SortBubbleShake(n20);
    SortBubbleShake(n21);
    SortBubbleShake(n22);
    SortBubbleShake(n23);

    SortCount(n30);
    SortCount(n31);
    SortCount(n32);
    SortCount(n33);
    bool check = true;
    for(int i = 0; i < 6999; i++)
    {
        if(n10->Get(i) > n10->Get(i+1) || n11->Get(i) > n11->Get(i+1) || n12->Get(i) > n12->Get(i+1) || n13->Get(i) > n13->Get(i+1))
        {
            check = false;
        }
        if(n20->Get(i) > n20->Get(i+1) || n21->Get(i) > n21->Get(i+1) || n22->Get(i) > n22->Get(i+1) || n23->Get(i) > n23->Get(i+1))
        {
            check = false;
        }
        if(n30->Get(i) > n30->Get(i+1) || n31->Get(i) > n31->Get(i+1) || n32->Get(i) > n32->Get(i+1) || n33->Get(i) > n33->Get(i+1))
        {
            check = false;
        }
    }
    for(int i = 0; i<30;i++)
    {
        cout<<endl;
    }
    if (check)
    {
        cout << "BUBBLE TEST PASSED"<<endl;
        cout << "SHAKE TEST PASSED"<<endl;
        cout << "COUNT_SORT TEST PASSED"<<endl;
        cout<<endl;
    }
}