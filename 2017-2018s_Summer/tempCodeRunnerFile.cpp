#include<iostream>
#include<vector>
using namespace std;
class H
{
    public:
      static void Sprint(vector<int> &a)
      {
          for (int i = 0; i < a.size();i++)
              cout << a[i] << " ";
      }
};

int main()
{
    vector<int> a(4, 100);
    H::Sprint(a);
    system("pause");
}