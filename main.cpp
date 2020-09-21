
#include <iostream>
#include "Numbers.hpp"
#include "Funktions.hpp"
#include "Tests.hpp"

using namespace std;
int main()
{
    Tests();
    Numbers<int>* n10 = FillNumRandIntArray(700);
    Numbers<int>* n11 = FillNumRandIntArray(700);
    Numbers<int>* n12 = FillNumRandIntArray(700);

    Numbers<int>* n20 = FillNumRandIntList(700);
    Numbers<int>* n21 = FillNumRandIntList(700);
    Numbers<int>* n22 = FillNumRandIntList(700);

    cout<<"BUBBLE ARRAY ";
    SortBubble(n10);
    cout<<"BUBBLE LIST ";
    SortBubble(n20);
    cout<<endl;
    cout<<"SHAKE ARRAY ";
    SortBubbleShake(n11);
    cout<<"SHAKE LIST ";
    SortBubbleShake(n21);
    cout<<endl;
    cout<<"COUNT ARRAY ";
    SortCount(n12);
    cout<<"COUNT LIST ";
    SortCount(n22);



}
