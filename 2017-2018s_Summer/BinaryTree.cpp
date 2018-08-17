#include<iostream>
#define MARK #
using namespace std;

template<class T> struct BiNode
{
    T data;
    BiNode *left;
    BiNode *right;
    BiNode(T da) : data(da), left(NULL), right(NULL){};
};

//如果给出元素是以先序的，那么可以这样构造二叉树比如 A B C # # D E # G # # F # # #
template<class T> BiNode<T> *Create(BiNode<T> * &root)
{
    T temp;
    cin >> temp;
    if(temp == "#")
        return;
    else
    {
        BiNode<T> *root = new BiNode<T>(temp);
        Create(root->left);
        Create(root->right);
    }
}


