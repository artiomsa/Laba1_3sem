#pragma once
template<class T>
void SortBubble(Numbers<T>* num, bool (*comp)(const T& a,const T& b))
{
    unsigned int start = clock();
    int w = 1;
    bool check = false;
    for(int i = 0; i < num->GetLength()-1;i++)
    {
        for(int j = 0; j<num->GetLength()-w;j++)
        {
            if(comp(num->Get(j),num->Get(j+1)))
            {
                T k = num->Get(j);
                T kk = num->Get(j+1);
                num->Set(k,j+1);
                num->Set(kk,j);
                check = true;
            }
        }
        if (check == false)
        {
            unsigned int stop = clock();
            cout <<"BUBBLE "<< (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
        check = false;
        w++;
    }
    unsigned int stop = clock();
    cout <<"BUBBLE "<< (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}
template <class T>
void SortBubbleShake(Numbers<T>* num, bool (*comp)(const T& a,const T& b))
{
    unsigned int start = clock();
    int left = 0;
    int right = num->GetLength();
    bool check = false;
    while(check == false)
    {
        for(int j = 0; j < right-1;j++)
        {
            if(comp(num->Get(j) , num->Get(j+1)))
            {
                T k = num->Get(j);
                T kk = num->Get(j+1);
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
                T k = num->Get(j);
                T kk = num->Get(j-1);
                num->Set(kk,j);
                num->Set(k,j-1);
                check = true;
            }
        }
        left++;
        if(check == false)
        {
            unsigned int stop = clock();
            cout <<"SHAKE "<< (stop - start)/(double)CLOCKS_PER_SEC<<endl;
            return;
        }
        if(check == true)
        {
            check = false;
        }
        if(left == right)
        {
            unsigned int stop = clock();
            cout <<"SHAKE "<< (stop - start)/(double)CLOCKS_PER_SEC<<endl;
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
    cout <<"COUNT "<< (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}
void SortCount(Numbers<double>* num)
{
    unsigned int start = clock();
    double min = 100;
    double max = 0;
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
    cout <<"COUNT "<< (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}
template<class T>
void quickSort(Numbers<T>* num, int left, int right, bool(*comp)(const T& a,const T& b)) {
    if (left >= right)
        return;
    int l = left;
    int r = right;
    T pivot = num->Get((r + l) / 2);
    while (l <= r) {
        while (comp(pivot, num->Get(l)))
            l++;
        while (comp(num->Get(r), pivot))
            r--;
        if(l>=r)
            break;
        if (l < r) {
            T temp = num->Get(r);
            num->Set(num->Get(l), r);
            num->Set(temp, l);
            l++;
            r--;
        }
    }
    quickSort(num, left, r, comp);
    quickSort(num, r + 1, right, comp);
}
template <class T>
void QuickSort(Numbers<T>* num, bool(*comp)(const T& a,const T& b))
{
    unsigned int start = clock();
    quickSort(num, 0, num->GetLength()-1,comp);
    unsigned int stop = clock();
    cout <<"QUICK "<< (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}
template<class T>
void InsertingSort(Numbers<T>* num, bool(*comp)(const T& a, const T& b))
{
    unsigned int start = clock();
    for(int i = 0; i < num->GetLength();i++)
    {
        for(int j = i; j > 0 && comp(num->Get(j-1),num->Get(j));j--)
        {
            T k = num->Get(j);
            num->Set(num->Get(j-1),j);
            num->Set(k,j-1);
        }
    }
    unsigned int stop = clock();
    cout <<"INSERTING " << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}
template<class T>
void ShellSort(Numbers<T>* num, bool(*comp)(const T& a, const T& b))
{
    unsigned int start = clock();
    int inc = 3;
    while (inc > 0)
    {
        for (int i = 0; i < num->GetLength(); i++)
        {
            int j = i;
            T temp = num->Get(i);
            while ((j >= inc) && comp(num->Get(j-inc),temp))
            {
                num->Set(num->Get(j - inc),j);
                j = j - inc;
            }
            num->Set(temp,j);
        }
        if (inc > 1)
            inc = inc / 2;
        else if (inc == 1)
            break;
    }
    unsigned int stop = clock();
    cout <<"SHELL " << (stop - start)/(double)CLOCKS_PER_SEC<<endl;
}