#include<iostream>
using namespace std;
template<class T> void HeapAdjust(T a[],int s,int m)
{
    T keyword = a[s];
    for (int j = s * 2; j <= m;j++)
    {
        if(j<m&&a[j]<a[j+1])
            j++;
        if(keyword>=a[j])
            break;
        a[s] = a[j];
        s = j;
    }
    a[s] = keyword;
}

template<class T> void HeapSort(T a[],int len)
{
    for (int i = len / 2; i > 0;i--)
        HeapAdjust(a, i, len);
    for (int i = len; i > 1;i--)
    {
        swap(a[1], a[i]);
        HeapAdjust(a, 1, i - 1);
    }
}

int main()
{
    int a[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    HeapSort(a, 8);
    for (int i = 1; i <= 8;i++)
        cout << a[i] << " ";
}