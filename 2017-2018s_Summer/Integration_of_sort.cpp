#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Sort
{
    public:
    /**非线性时间排序->交换排序->冒泡排序**////////////////////////////////////////
      static void BubbleSort1(vector<T> &a);
      //如果全部没有发生交换代表已经排好序了
      static void BubbleSort2(vector<T> &a);
      //记录下每轮标记的最后位置然后下次从头部开始遍历这个位置就ok
      static void BubbleSOrt3(vector<T> &a);
      /**非线性时间排序->交换排序->快排**///////////////////////////////////////////
      int Partition1(vector<T> &a, int low, int high);
      int Partition2(vector<T> &a, int low, int high);
      static void QSort(vector<T> &a, int low, int high);
      /***非线性时间排序->交换排序->鸡尾酒排序*///////////////////////////////////
      static void CocktailSort1(vector<T> &a);
      //鸡尾酒针对有序区的改进算法，可以记录下最后一次元素的交换位置
      static void CocktailSort2(vector<T> &a);
      /***非线性时间排序->插入排序->简单插入排序***////////////////////////////////
      static void InsertSort(vector<T> a);
      /***非线性时间->插入排序->折半插入排序***////////////////////////////////////
      static void BInsertSort(vector<T> &a);
      /***非线性时间->插入排序->2-路插入排序***///////////////////////////////////
      static void TwoPathInsert1(vector<T> &a);
      ///利用折半查找找到需要插入的位置
      static void TwoPathInsert2(vector<T> &a);
      /***非线性时间排序->插入排序->表插入排序***//////////////////////////////////

      /***非线性时间排序->插入排序->Shell排序***///////////////////////////////////
      void ShellInsert(T a[], int dk, int len);
      void ShellSort(T a[], int delta[], int len, int t);
};

template <class T>
void Sort<T>::BubbleSort1(vector<T> &a)
{

}