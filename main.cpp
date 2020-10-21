
#include <iostream>
#include "Numbers.hpp"
#include "Funktions.hpp"
#include "Tests.hpp"
#include "Sorts.hpp"
#include "LinkedList.hpp"
using namespace std;
//реверс односв списка
//bool comp11(const int& temp)
//{
//    return temp > 5;
//}
int main() {
//    int arr [20];
//    for(int i = 0; i < 20;i++)
//    {
//        arr[i] = i;
//    }
//    LinkedList<int>* list = new LinkedList<int>(arr,20);
//    list->Reverse();
//    list->Delete(comp11);
//
//    for(int i = 0; i < list->GetLength();i++)
//    {
//        cout << list->Get(i) << endl;
//    }
    Tests();
    bool contkey = true;
    while (contkey == true)
    {
        cout<< "Array->1 List->2 Exit->0"<<endl;
        int operationcode1;
        cin >> operationcode1;
        if(operationcode1 == 1)
        {
            cout<< "Chose count of elements"<<endl;
            int count;
            cin>>count;
            Numbers<int>* num = FillNumRandIntArray(count);
            cout<< "Inserting->1 Quick->2 Shell->3 Count->4 Shake->5 Bubble->6"<<endl;
            int operationcode2;
            cin>>operationcode2;
            if(operationcode2 == 1)
            {
                InsertingSort(num,comp1);
            }
            if(operationcode2 == 2)
            {
                QuickSort(num,comp1);
            }
            if(operationcode2 == 3)
            {
                ShellSort(num,comp1);
            }
            if(operationcode2 == 4)
            {
                SortCount(num);
            }
            if(operationcode2 == 5)
            {
                SortBubbleShake(num,comp1);
            }
            if(operationcode2 == 6)
            {
                SortBubble(num,comp1);
            }
        }
        if(operationcode1 == 2)
        {
            cout<< "Chose count of elements"<<endl;
            int count;
            cin>>count;
            Numbers<int>* num = FillNumRandIntList(count);
            cout<< "Inserting->1 Quick->2 Shell->3 Count->4 Shake->5 Bubble->6"<<endl;
            int operationcode2;
            cin>>operationcode2;
            if(operationcode2 == 1)
            {
                InsertingSort(num,comp1);
            }
            if(operationcode2 == 2)
            {
                QuickSort(num,comp1);
            }
            if(operationcode2 == 3)
            {
                ShellSort(num,comp1);
            }
            if(operationcode2 == 4)
            {
                SortCount(num);
            }
            if(operationcode2 == 5)
            {
                SortBubbleShake(num,comp1);
            }
            if(operationcode2 == 6)
            {
                SortBubble(num,comp1);
            }
        }
        if(operationcode1 == 0)
        {
            break;
        }
    }
}
