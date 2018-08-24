#include<iostream>
#define MIN -1000000
using namespace std;
int const MAX=10000;
int a[MAX]={-2, -3, 4, -1, -2, 1, 5, -3};

int crossingMiddle(int l,int m,int r)
{
    int left_max = MIN,right_max=MIN;
    int sum = 0;
    for (int i = m; i >= l;i--)
    {
        sum += a[i];
        if(sum>left_max)
            left_max = sum;
    }
    for (int i = m + 1; i <= r;i++)
    {
        sum += a[i];
        if(sum>right_max)
            right_max = sum;
    }
    return left_max + right_max;
}

int max_subarray(int l,int r)
{
    int m = (l + r) / 2;
    if(m==l)
        return a[l];
    else
        return max(max(max_subarray(l, m), crossingMiddle(l, m, r)), max_subarray(m + 1, r));
}

int main()
{ 
    cout << max_subarray(0, 7);
}