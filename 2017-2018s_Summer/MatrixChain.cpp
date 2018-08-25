#include<iostream>
#include<cstring>
#define N 6
using namespace std;
//example:  A1      A2      A3      A4      A5      A6
//          30*35   35*15   15*5    5*10    10*20   20*25
//          p0 p1      p2     p3      p4       p5      p6
//procedure:
//m[1][1]...m[6][6]=0 initialize...
//m[1][2] m[2][3] m[3][4] m[4][5] m[5][6]
//m[1][3] m[2][4] m[3][5] m[4][6]
//...
//m[1][5] m[2][6]
//m[1][6]


void MatrixChain(int **m,int n,int *p,int **s)
{
    for (int i = 1; i <= n;i++)
        m[i][i] = 0;
    for (int r = 2; r <= n;r++)//the surrounding loop executes n-r+1 times
    {
        for (int i = 1; i <= n - r + 1;i++)//keep the same times
        {
            int j = i+r-1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//at the start, set k=i, so we get a default m[i][j]
            for (int k = i + 1; k < j;k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(m[i][j]>t)
                {
                    m[i][j] = t;
                    s[i][j] = k;
                } 
            }
        }
    }
}

int main()
{
    int **m = new int *[N + 1];
    int **s = new int *[N + 1];
    int *p = new int[N + 1];
    for (int i = 0; i <= N;i++)
    {
        m[i] = new int[N + 1];
        s[i] = new int[N + 1];
        memset(m[i], 0, (N + 1) * sizeof(int));
        memset(s[i], 0, (N + 1) * sizeof(int));
        cin >> p[i];
    }
    MatrixChain(m, N, p, s);
    for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
        cout << m[1][N];
}