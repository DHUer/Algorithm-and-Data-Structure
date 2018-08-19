#include<iostream>
using namespace std;
#define V 5
#define MAX 99999

int minKey(int key[V],bool isInMinSet[V])
{
    int minTem = MAX, index;
    for (int i = 0; i < V;i++)
        if(!isInMinSet[i]&&minTem>key[i])
            minTem = key[i],index=i;
    return index;
}

void printMST(int graph[V][V],int parent[V],int key[V])
{
    for (int i = 1;i<V;i++)
        cout << parent[i] << "-" <<i<<": " << graph[i][parent[i]] << endl;
}

void MiniSpanTree_prim(int graph[V][V])
{
    int key[V], parent[V];
    bool isInMinSet[V];
    for (int i = 0;i<V;i++)
        key[i]=MAX,isInMinSet[i] = false;
    key[0] = 0, parent[0] = -1;//designate the first point by hand
    for (int i = 0; i < V;i++)//V or V-1??
    {
        int u = minKey(key, isInMinSet);
        isInMinSet[u] = true;
        for (int v = 0; v < V;v++)
        if(!isInMinSet[v]&&graph[u][v]&&graph[u][v]<key[v])
            key[v] = graph[u][v], parent[v] = u;
    }
    printMST(graph, parent, key);
}

int main()
{
    int graph[V][V] =
        {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}};
    MiniSpanTree_prim(graph);
}