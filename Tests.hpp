#pragma once
#include "Sequence.hpp"
#include "Funktions.hpp"
#include "Sorts.hpp"
void Tests() {
    Numbers<double>* n10 = FillNumRandDoubleArray(700);
    Numbers<int>* n11 = FillNumRandIntArray(700);
    Numbers<int>* n12 = FillNumRandIntList(700);
    Numbers<double>* n13 = FillNumRandDoubleList(700);

    Numbers<double>* n20 = FillNumRandDoubleArray(700);
    Numbers<int>* n21 = FillNumRandIntArray(700);
    Numbers<int>* n22 = FillNumRandIntList(700);
    Numbers<double>* n23 = FillNumRandDoubleList(700);

    Numbers<double>* n30 = FillNumRandDoubleArray(700);
    Numbers<int>* n31 = FillNumRandIntArray(700);
    Numbers<int>* n32 = FillNumRandIntList(700);
    Numbers<double>* n33 = FillNumRandDoubleList(700);

    Numbers<double>* n40 = FillNumRandDoubleArray(700);
    Numbers<int>* n41 = FillNumRandIntArray(700);
    Numbers<int>* n42 = FillNumRandIntList(700);
    Numbers<double>* n43 = FillNumRandDoubleList(700);

    Numbers<double>* n50 = FillNumRandDoubleArray(700);
    Numbers<int>* n51 = FillNumRandIntArray(700);
    Numbers<int>* n52 = FillNumRandIntList(700);
    Numbers<double>* n53 = FillNumRandDoubleList(700);

    Numbers<double>* n60 = FillNumRandDoubleArray(700);
    Numbers<int>* n61 = FillNumRandIntArray(700);
    Numbers<int>* n62 = FillNumRandIntList(700);
    Numbers<double>* n63 = FillNumRandDoubleList(700);

    cout << "double ARRAY ";
    SortBubble(n10,comp1);
    cout << "int ARRAY ";
    SortBubble(n11,comp1);
    cout << "int LIST ";
    SortBubble(n12,comp1);
    cout << "double LIST ";
    SortBubble(n13,comp1);
    cout << ""<<endl;

    cout << "double ARRAY ";
    SortBubbleShake(n20,comp1);
    cout << "int ARRAY ";
    SortBubbleShake(n21,comp1);
    cout << "int LIST ";
    SortBubbleShake(n22,comp1);
    cout << "double LIST ";
    SortBubbleShake(n23,comp1);
    cout << ""<<endl;

    cout << "double ARRAY ";
    SortCount(n30);
    cout << "int ARRAY ";
    SortCount(n31);
    cout << "int LIST ";
    SortCount(n32);
    cout << "double LIST ";
    SortCount(n33);
    cout << ""<<endl;

    cout << "double ARRAY ";
    QuickSort(n40,comp1);
    cout << "int ARRAY ";
    QuickSort(n41,comp1);
    cout << "int LIST ";
    QuickSort(n42,comp1);
    cout << "double LIST ";
    QuickSort(n43,comp1);
    cout << ""<<endl;

    cout << "double ARRAY ";
    InsertingSort(n50,comp1);
    cout << "int ARRAY ";
    InsertingSort(n51,comp1);
    cout << "int LIST ";
    InsertingSort(n52,comp1);
    cout << "double LIST ";
    InsertingSort(n53,comp1);
    cout << ""<<endl;

    cout << "double ARRAY ";
    ShellSort(n60,comp1);
    cout << "int ARRAY ";
    ShellSort(n61,comp1);
    cout << "int LIST ";
    ShellSort(n62,comp1);
    cout << "double LIST ";
    ShellSort(n63,comp1);
    cout << ""<<endl;



    bool check = true;
    for(int i = 0; i < 699; i++)
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
        if(n40->Get(i) > n40->Get(i+1) || n41->Get(i) > n41->Get(i+1) || n42->Get(i) > n42->Get(i+1) || n43->Get(i) > n43->Get(i+1))
        {
            check = false;
        }
        if(n50->Get(i) > n50->Get(i+1) || n51->Get(i) > n51->Get(i+1) || n52->Get(i) > n52->Get(i+1) || n53->Get(i) > n53->Get(i+1))
        {
            check = false;
        }
        if(n60->Get(i) > n60->Get(i+1) || n61->Get(i) > n61->Get(i+1) || n62->Get(i) > n62->Get(i+1) || n63->Get(i) > n63->Get(i+1))
        {
            check = false;
        }

    }

        cout<<endl;

    if (check)
    {
        cout << "BUBBLE TEST PASSED"<<endl;
        cout << "SHAKE TEST PASSED"<<endl;
        cout << "COUNT SORT TEST PASSED"<<endl;
        cout << "QUICK SORT TEST PASSED" <<endl;
        cout << "INSERTING SORT TEST PASSED" <<endl;
        cout << "SHELL SORT TEST PASSED" <<endl;
        cout<<endl;
    }
}