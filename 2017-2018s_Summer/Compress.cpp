//s[i]=min{s[i-k]+k*bmax(i-k+1,i)}+11 (k>=1&&k<=min{i,256})
#include<iostream>
#include<cmath>
#include<ctime>
#define N 120
using namespace std;
int s[N + 1], p[N + 1];


int bmax(int i,int j)
{
    int max = ceil(log(p[i]) / log(2));
    for (int k = i+1; k <= j;k++)
    {
        int tem = floor(log(p[i]) / log(2)+1);
        cout << tem << " ";
        if(max<tem)
            max = tem;
    }
    cout << max <<" ";
    return max;
}

void Compress()
{
    int Lmax = 256;
    s[0] = 0;
    for (int i = 1; i <= N;i++)
    {
        s[i] = s[i - 1] + bmax(i, i);
        for (int k = 2; k <= i && k <= Lmax;k++)
        {
            int tem = s[i - k] + bmax(i, k);
            if(s[i]>tem)
                tem = s[i];
        }
    }
}

int main()
{
    srand(time(NULL));
    for (int i = 1; i <= N;i++)
        p[i] = rand() % 256;
    Compress();
    cout <<endl<< endl;
    cout << s[N];
}

