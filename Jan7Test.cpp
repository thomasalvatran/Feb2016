#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//functor
struct isOdd  //no need public defined, struct everything is public, class everything is private
{
    bool operator()(int x)
    {
        return x % 2;
    }
};
bool isEven(int x)
{
    // cout << "Function " << x << endl;
    return !(x % 2);
}

// class IsMultipleOf
// {
//   int m_multi;
// public:
//   IsMultipleOf(int multi) : m_multi(multi){}
//   bool operator ()(int x) { return !(x % m_multi); }
// };

//Functor can be class or struct overload operator()
struct IsMultipleOf
{
    int m_multi;
    IsMultipleOf(int multi) : m_multi(multi){ cout << "ctor" << endl; }
    bool operator()(int x) { cout << "operator" << endl; return !(x % m_multi); }
};
int multi1 = 3;
bool isMultipleOf(int x)
{
    return !(x % multi1);
}

bool isMultipleOf1(int x)  //why can't overloading have to give a new name
{
    if (x == 0 || x == 3)
       return true;
    if (x < 3)
       return false;
  return !(x % 3);
}
int main()
{
  vector<int> col = { 0, 1, 2, 3 , 4, 5, 6, 7, 8, 15, 18 };
  int multi = 3;
  int c1 = count_if(col.begin(), col.end(), isOdd()); //struct
  size_t c2 = count_if(col.begin(), col.end(), isEven); //function
  size_t c3 = count_if(col.begin(), col.end(), [](int x) { return x % 2; }); //lambda
  size_t c4 = count_if(col.begin(), col.end(), [multi](int x) { return !(x % multi); }); //lambda
  size_t c5 = count_if(col.begin(), col.end(), IsMultipleOf(multi));  // struct (or class)
  size_t c6 = count_if(col.begin(), col.end(), isMultipleOf);  //??? iterator element automatic
  size_t c7 = 0;
  for (int i = 0; i < col.size(); i++)
  { 
        if (isMultipleOf1(col[i]))
        {
            cout << col[i] << endl;
            c7++;
        }
  }
  cout << c1 << " " << c2 << " " << c3 <<" " << c4 << " " << c5 << " " << c6 << " " << c7 << endl;
    
}