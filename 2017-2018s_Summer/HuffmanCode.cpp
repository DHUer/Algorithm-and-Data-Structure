#include<iostream>
#include<cstring>
using namespace std;
#define MAX 1000000
typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree; 

void Select(HuffmanTree HT,int end,int &s1,int &s2)
{
    int temp_weight =MAX;    
    for (int i = 0; i < end;i++)
    {
        if(temp_weight>=HT[i].weight&&HT[i].parent==0)
        {
            s1 = i;
            temp_weight = HT[i].weight;
        }
    }
    temp_weight = MAX;
    for (int i = 0; i < end;i++)
    {
        if(s1!=i&&HT[i].parent==0&&temp_weight>=HT[i].weight)
        {
            s2 = i;
            temp_weight = HT[i].weight;
        }
    }
}


void HuffmanCoding(HuffmanTree &HT,char ** &HC,int *w,int n)
{
    if(n<=1)
        return;
    int m = 2 * n - 1,i;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    HuffmanTree p = HT;
    for (i = 0; i < n;i++,p++,w++)
        *p = {*w, 0, 0, 0};
    for (; i <= m;i++,p++)
        *p = {0, 0, 0, 0};
    for (i = n; i < m; i++) //建Huffman树
    {
        int s1, s2;
        //在HT[0..i)中选择parent为0，且weight最小的两个结点，其中的序号分别为s1和s2
        Select(HT, i, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    //求HuffmanCode
    HC = (char **)malloc((n + 1) * sizeof(char *));
    char * cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    int start;
    for (i = 0; i < n;i++)
    {
        start = n - 1;
        for (int c = i, f = HT[i].parent; f != 0;c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    HuffmanTree HT;
    char **hc;
    HuffmanCoding(HT, hc, freq, 6);
    for (int i = 0; i < 6;i++)
        cout <<arr[i]<<":"<< hc[i] << endl;
    system("pause");
}