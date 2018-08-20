/*
q(n,m):
    q(n,1)=1;n>=1
    q(n,m)=q(n,n);m>=n
    q(n,n)=1+q(n,n-1);
q(n,m)=q(n,m-1)+q(n-m,m);n>m>1
*/
#include<iostream>
using namespace std;
int q(int n,int m)
{
    if(n<1||m<1)
        return 0;
    if(n>=1&&m==1)
        return 1;
    if(m>=n)
        return q(n, n - 1) + 1;
    if(n>m&&m>1)
        return q(n, m - 1) + q(n - m, m);
}
int main()
{
    cout << q(6, 6);
}