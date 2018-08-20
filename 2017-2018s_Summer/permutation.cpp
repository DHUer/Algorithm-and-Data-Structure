/*Perm(R)=(r1)Perm(R1)+(r2)Perm(R2)...+(rn-1)Perm(Rn-1)*/
#include<iostream>
using namespace std;

template<class T> void Perm(T a[],int k,int len)
{
    if(k==len)
    {
        for (int i = 0;i<len;i++)
            cout << a[i] << " ";
        cout << endl;
    }
    else 
    for (int i = k; i < len;i++)
    {
        swap(a[i], a[k]);
        Perm(a, k + 1, len);
        swap(a[i], a[k]);
    }
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    Perm(a, 0, 6);
}