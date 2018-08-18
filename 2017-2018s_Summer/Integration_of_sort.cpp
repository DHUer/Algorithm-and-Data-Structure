#include<iostream>
#include<vector>
#include<ctime>
#define  MAX 100000
using namespace std;

template<class T> struct LNode
{
  T value;
  int next;
  LNode(T va, int n=0) : value(va), next(n){};
};
template<class T>
class Sort
{
    public:
    /*非线性时间排序->交换排序->冒泡排序*/
      static void BubbleSort1(vector<T> &a);
      //如果全部没有发生交换代表已经排好序了
      static void BubbleSort2(vector<T> &a);
      //记录下每轮标记的最后位置然后下次从头部开始遍历这个位置就ok
      static void BubbleSort3(vector<T> &a);
      /**非线性时间排序->交换排序->快排***/
      static int Partition1(vector<T> &a, int low, int high);
      static int Partition2(vector<T> &a, int low, int high);
      static void QSort(vector<T> &a, int low, int high);
      /***非线性时间排序->交换排序->鸡尾酒排序***/
      static void CocktailSort1(vector<T> &a);
      //鸡尾酒针对有序区的改进算法，可以记录下最后一次元素的交换位置
      static void CocktailSort2(vector<T> &a);
      /***非线性时间排序->插入排序->简单插入排序***/
      static void InsertSort(vector<T> &a);
      /***非线性时间->插入排序->折半插入排序***/
      static void BInsertSort(vector<T> &a);
      /***非线性时间->插入排序->2-路插入排序***/
      static void TwoPathInsert1(vector<T> &a);
      ///利用折半查找找到需要插入的位置
      static void TwoPathInsert2(vector<T> &a);
      /***非线性时间排序->插入排序->Shell排序***/
      static void ShellInsert(vector<T> &a, int dk);
      static void ShellSort(vector<T> &a, int delta[],int len);
      /***非线性时间排序->插入排序->表插入排序***/
      static void InitList(vector<LNode<T>> &t,const vector<T> &a);
      static void TableInsertSort(vector<T> &a);
};


template <class T> void Sort<T>::BubbleSort1(vector<T> &a)
{
  for (int i = 0; i < a.size();i++)
  {
    for (int j = 1; j < a.size() - i;j++)
    {
      if(a[j]<a[j-1])
        swap(a[j], a[j - 1]);
    }
  }
}

template <class T> void Sort<T>::BubbleSort2(vector<T> &a)
{
  bool isSorted = false;
  for (int i = 0; i < a.size()&&!isSorted;i++)
  {
    isSorted = true;
    for (int j = 1; j < a.size() - i;j++)
    {
      if(a[j]<a[j-1])
        swap(a[j], a[j - 1]);
      isSorted = false;
    }
  }
}

template<class T> void Sort<T>::BubbleSort3(vector<T> &a)
{
  bool isSorted = false;
  int lastPos = a.size();
  int nextPos = a.size();
  do
  {
    isSorted = true;
    for (int j = 1;j<lastPos;j++)
    {
      if(a[j]<a[j-1])
      {
        swap(a[j], a[j - 1]);
        isSorted = false;
        nextPos = j;
      }
    }
    lastPos = nextPos;
  } while (!isSorted);
}

template<class T> int Sort<T>::Partition2(vector<T> &a,int low,int high)
{
  int key = a[low];
  while(low<high)
  {
    while(low<high&&a[high]>=key)//一定要加等号要不然就会产生死循环
      high--;
    a[low] = a[high];//Partition1在于这里用到了swap但是由于swap会产生三次移动所以，但是我们只需要记住pivot的位置，所以操作时多余的
    while(low<high&&a[low]<=key)
      low++;
    a[high] = a[low];
  }
  a[low] = key;
  return low;
}

template<class T> void Sort<T>::QSort(vector<T> &a,int low,int high)
{
  if(low<high)//刚开始居然把这里写成了while。。。
  {
    int pivot = Partition2(a, low, high);
    QSort(a, low, pivot-1);
    QSort(a, pivot + 1, high);
  }
}

template<class T> void Sort<T>::CocktailSort2(vector<T> &a)//CockTailSort1没有用到isSorted
{
  int low = 0, high = a.size();
  int newLow, newHigh;
  bool isSorted = false;
  do
  {
    isSorted = true;
    for (int i = low + 1; i < high;i++)
    if(a[i]<a[i-1])
    {
      swap(a[i], a[i - 1]);
      isSorted = false;
      newHigh = i;
    }
    high = newHigh;
    for (int j = high - 1;j>low;j--)
    if(a[j]<a[j-1])
    {
      swap(a[j], a[j - 1]);
      isSorted = false;
      newLow = j;
    }
    low = newLow;
  } while (!isSorted);
}

template<class T> void Sort<T>::InsertSort(vector<T> &a)
{
  for (int i = 1; i < a.size();i++)
  {
    if(a[i]<a[i-1])
    {
      T temp = a[i];
      int j;
      for ( j = i; j > 0 && a[j - 1] > temp;j--)
        a[j] = a[j - 1];
      a[j] = temp;
    }
  }
}

template<class T> void Sort<T>::BInsertSort(vector<T> &a)
{
  for (int i = 1; i < a.size();i++)
  {
    if(a[i]<a[i-1])
    {
      T temp = a[i];
      /*...*///效率较简单插入排序区别不大
    }
  }
}

template<class T> void Sort<T>::ShellSort(vector<T> &a, int delta[],int len)
{
  for (int i = 0; i < len;i++)
  {
    ShellInsert(a, delta[i]);
  }
}

template<class T> void Sort<T>::ShellInsert(vector<T> &a,int dk)
{
  for (int i = 1 + dk; i < a.size();i++)
  {
    if(a[i-1]>a[i])
    {
      T temp = a[i];
      int j;
      for (j = i; j > 0 && temp < a[j - 1];j-=dk)
        a[j] = a[j - dk];
      a[j] = temp;
    }
  }
}

template<class T> void Sort<T>::TwoPathInsert1(vector<T> &a)//感觉这里用不用二分查找来定位元素都没有太大的关系，因移动的次数是不变的
{
  //由于空间复杂度为n所以其实用处不大。。。而且时间复杂度为n2
  int front, tail;
  front = tail = 0;
  vector<T> b(a.size(),0);
  b[0] = a[0];
  for (int i = 1; i < a.size();i++)
  {
    if(a[i]<b[front])
    {
      front = (front - 1 + a.size()) % a.size();
      b[front] = a[i];
    }
    else if(a[i]>b[tail])
    {
      tail++;
      b[tail] = a[i];
    }
    else
    {
      //开始移动元素来使结果有序
      int j;
      for (j = tail+1; b[(j-1+a.size())%a.size()] > a[i];j=(j-1+a.size())%a.size())//注意这里的起始点是tail+1
        b[j] = b[(j - 1+a.size())%a.size()];
      b[j] = a[i];
      tail++;
    }
  }
  for(int i=0;i < a.size();i++)
    a[i] = b[(front + i) % a.size()];
}

template<class T> void Sort<T>::InitList(vector<LNode <T>> &t,const vector<T> &a)
{
  LNode<T> tem(MAX,1);
  t.push_back(tem);
  for (int i = 0; i < a.size();i++)
  {
    LNode<T> tem(a[i]);
    t.push_back(tem);
  }
}

template <class T> void Sort<T>::TableInsertSort(vector<T> &a)
{
  vector<LNode<T>> t;
  InitList(t,a);
  for (int i = 2; i < t.size();i++)
  {
    int p, q;
    q = 0;
    p = t[0].next;
    while(t[p].value<t[i].value)//居然把这个地方刚开始写成a[i]了。。。
    {
      q = p;//这里的q相当于要寻找的插入的位置,整个结构类似于链表
      p = t[p].next;
    }
    t[q].next = i;
    t[i].next = p;
  }
  int p=t[0].next,re=0;
  while(p!=0)
  {
    a[re++] = t[p].value;
    p = t[p].next;
  }
}
int main()
{
  vector<int> a;
  srand(time(0));
  for(int i=0;i<4;i++)
    a.push_back(rand() % 50);
  //int delta[2] = {3, 1};
  //Sort<int>::BubbleSort1(a);
  //Sort<int>::BubbleSort2(a);
  //Sort<int>::BubbleSort3(a);
  //Sort<int>::QSort(a, 0, a.size() - 1);
  //Sort<int>::CocktailSort2(a);
  //Sort<int>::InsertSort(a);
  //Sort<int>::ShellSort(a, delta, 2);
  //Sort<int>::TwoPathInsert1(a);
  Sort<int>::TableInsertSort(a);
  for(int t:a)
  {
    cout << t << " ";
  }
  system("pause");
}