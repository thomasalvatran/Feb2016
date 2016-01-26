// http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
#include <iostream>
#include <vector>
#include <limits>

using namespace std;
const int SIZE = 3; /* height, width, lenght dynamic size using vector.push */

template <typename T>
class Box
{
  
  std::vector<T> m_vec;  //no size vec(2) initiate in ctor
  public:
  
  Box operator+(Box& b) 
  {
      // Box box(0, 0, 0);
      Box box;
      box.m_vec[0] = this->m_vec[0] + b.m_vec[0];
      box.m_vec[1] = this->m_vec[1] + b.m_vec[1];
      box.m_vec[2] = this->m_vec[2] + b.m_vec[2];
      return box;
  }
  Box(Box box(T a, T b, T c))  //vector size in ctor
  { 
  cout << "Ctor" << endl;
  box.push_back(box.a);
  box.push_back(box.b);
  box.push_back(box.c);
  } 
  template <typename D>
  Box(vector<D> vec) // : m_vec(SIZE) //vector size in ctor
  { 
    // m_vec[0] = height; no SIZE in vector synamic array (vector)
    // m_vec[1] = width;
    // m_vec[2] = lenght;
    cout << "Ctor1" << endl;
    for(typename vector<D>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
      cout << *iter << endl;
    }
  } 
  Box()  
  { 
    cout <<"Ctor" << endl; //initialize to 0
    m_vec.push_back(0);
    m_vec.push_back(0);
    m_vec.push_back(0);
  }
  void showBox(Box box(T a, T b, T c))
  {
    cout << "height = "<< box.a.m_vec[0] << endl;
    cout << "wodth = "<< box.b.m_vec[1] << endl;
    cout << "lenght = "<< box.c.m_vec[2] << endl;
  }
  void showBox(Box box)
  {
    cout << "height = "<< box.m_vec[0] << endl;
    cout << "width = "<< box.m_vec[1] << endl;
    cout << "lenght = "<< box.m_vec[2] << endl;
  }
};

int main()
{
  // vector<int> v(2);
  int array[] = {1, 2, 3, 4};
  vector<int> v1(array);
  // Box<int> box1(1, 2, 3, 5);
  // Box<int> box2(3, 4, 5, 7);
  // Box<int> box = box1 + box2;
  // box.showBox(box);
  
  // cout << box.m_vec[0] << endl;  //m_vec is private
  // cout << box.m_vec[1] << endl; 
  // cout << box.m_vec[2] << endl;
}