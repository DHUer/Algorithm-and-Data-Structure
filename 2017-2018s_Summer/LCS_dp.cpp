#include<iostream>
using namespace std;
/*
8 9
B C D B A B C C
A D A C B A C D C*/
void LCS_dp(int m, int n, char *x, char *y, int **c, int **b)
{
    for (int i = 0; i <= m;i++)
        c[i][0] = 0;
    for (int i = 0; i <= n;i++)
        c[0][i] = 0;
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
}

void LCS_print(int i, int j, char *x,int **b)
{
    if(i==0||j==0)
        return;
    if(b[i][j]==1)
    {
        LCS_print(i - 1, j - 1, x, b);
        cout << x[i];
    }
    else if (b[i][j] == 2)
        LCS_print(i - 1, j, x, b);
    else
        LCS_print(i, j - 1, x, b);
}

int main()
{
    int m, n;
    cin >> m >> n;
    getchar();
    char *x = new char[m + 1];
    char *y = new char[n + 1];
    int **c = new int *[m + 1];
    int **b = new int *[m + 1];
    for (int i = 1; i <m+1; i++)
        cin >> x[i];
    getchar();
    for (int i = 1; i < n + 1; i++)
    {
        cin >> y[i];
        c[i-1] = new int[n + 1];
        b[i-1] = new int[n + 1];
    }
    c[m] = new int[n + 1];
    b[m] = new int[n + 1];
    LCS_dp(m, n, x, y, c, b);
    LCS_print(m, n, x, b);
    return 0;
}
