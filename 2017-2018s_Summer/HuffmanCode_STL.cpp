#include<iostream>
#include<queue>
#include<cstring>
#define Pare $
using namespace std;
template<class T> struct MinHeapNode
{
    T data;
    unsigned fre;
    MinHeapNode *lchild, *rchild;
    MinHeapNode(T d, unsigned f) : data(d), fre(f)
    {
        lchild = NULL;
        rchild = NULL;
    };
};
template <class T> struct compare
{
    bool operator()(const MinHeapNode<T> *l, const MinHeapNode<T> *r)
    {
        return (l->fre > r->fre);
    }
};

template<class T> void printCodes(MinHeapNode<T> *root,string str)
{
    if(root==NULL) return;
    if(root->data!='$')
        cout << root->data << ":" << str << endl;
    printCodes(root->lchild, str + "0");
    printCodes(root->rchild, str + "1");
}

template<class T> void HuffmanTree(T *res,unsigned * f,int size)
{
    priority_queue<MinHeapNode<T> *, vector<MinHeapNode<T> *>, compare<T>> minHeap;
    for(int i=0;i<size;i++)
        minHeap.push(new MinHeapNode<T>(res[i], f[i]));
    MinHeapNode<T> *left, *right,*top;
    while(minHeap.size()!=1)
    {
        left=minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode<T>('$', left->fre + right->fre);
        top->lchild = left;
        top->rchild = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanTree<char>(arr, freq, size);
}