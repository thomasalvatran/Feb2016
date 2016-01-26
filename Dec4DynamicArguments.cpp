// http://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c
//home/tovantran/Ctest/Dec4DynamicArguments.cpp --> 2015-12-08 by ./.tv  owner: tovantran

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

template <class T>
class Box 
{
  vector<T> m_vec;
  int size;
  public:
  Box operator+(Box& b)
  {
      Box box(this->size);  //ctor: set vector size to write in otherwise use push_back
      for (int i = 0; i < this->size; i++)
      {
        box.m_vec[i] = this->m_vec[i] + b.m_vec[i];
      }
    
      box.size = this->size; //set lenght for this vector
      return box;
  }
  Box(vector<T> vec)
  {
      cout << "Ctor" << endl;
     int i = 0;
     for(typename vector<T>::iterator iter = vec.begin(); iter != vec.end(); ++iter, i++)
     {
         m_vec.push_back(*iter);
     }
     size = i;
  }
  Box(int size) : m_vec(size) { cout <<"Default Ctor "<< size << endl; }
  void showBox()
  {
    for_each(begin(m_vec), end(m_vec),[](T x) { //lambda
        cout << setprecision(4) << x << " ";
    });
    cout << endl;
  }
  ~Box() { cout << "Dtor" << endl; }
  int getsize() { return size; }
};

template <typename D>
void test()
{
    vector<D> v = {10.55, 20, 30, 40, 45, 101, 12, 111, 1, 2, 3, 4};
    vector<D> v1 = {11, 22, 33, 44, 55, 99, 14, 1};
   
    Box<D> box1(v);
    Box<D> box2(v1);
    // Box<D> box(v.size()); //why can't Box<int> box = box1 + box2
    Box<D> box = box1 + box2;
    // box = box1 + box2;
    cout << box.getsize() << endl;
    box.showBox();
}

int main()
{
   test<float>();  //change type just one.
   return 0;
}