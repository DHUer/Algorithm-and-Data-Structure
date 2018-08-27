//c[i][j]=0 (i=0,j=0)
//          c[i-1][j-1] (xi==yj)
//          max{c[i][j-1],c[i-1][j]}(xi!=yj)

#include<iostream>
#include<vector>
#define M 8
#define N 9
using namespace std;
char x[M+1], y[N+1];

int LCS_recursive(int i,int j)
{
    if(i==0||j==0) return 0;
    if(x[i]==y[j])
        return LCS_recursive(i - 1, j - 1) + 1;
    else
        return max(LCS_recursive(i - 1, j), LCS_recursive(i, j - 1));
}

int main()
{
    for (int i = 1; i <= M;i++)
        cin >> x[i];
    for (int i = 1; i <= N;i++)
        cin >> y[i];
    cout<<LCS_recursive(M, N);
}