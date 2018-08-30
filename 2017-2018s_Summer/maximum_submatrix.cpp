#include<iostream>
#include<cstring>
#define MIN -999999
using namespace std;

int maxSum(int n,int *a)
{
    int local_sum = 0, global__sum = MIN;
    for (int i = 1; i <= n;i++)
    {
        local_sum = local_sum + a[i];
        local_sum = max(local_sum, a[i]);
        global__sum = max(local_sum, global__sum);
    }
    return global__sum;
}

int maxSum_matrix(int **a,int m,int n)
{
    int sum = 0;
    for (int i = 1; i <= m;i++)
    {
        int *b = new int[n + 1];
        memset(b, 0, sizeof(int) * (n + 1));
        for (int j = i; j <= m;j++)
        {
            for (int k = 1; k <= n;k++)
                b[k] += a[j][k];
            int max = maxSum(n, b);
            if(max>sum)
                sum = max;
        }
    }
    return sum;
}

int main()
{
    int a[9] = {0, -3, 4, -1, -2, 1, 5, -3, 9};
    cout << maxSum(8, a);
}