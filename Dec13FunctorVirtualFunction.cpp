// http://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html
//http://stackoverflow.com/questions/1955074/virtual-methods-or-function-pointers
//Keywords: Functor, virtual function , function pointer, overload, overidde
//home/tovantran/Ctest/Dec13FunctorVirtualFunction.cpp --> 2015-12-13 by ./.tv  owner: tovantran

#include <iostream>
using namespace std;


class MathComputer    //virtual function + Functor operator()
{
    public:
    virtual int computerResult(int x, int y) = 0;  //Virtual function (Overload at run time)
    int operator()(int x, int y)
    { 
		  cout << "Function obj or Functor " << endl;
		  return x * y; 
    }  //Functor
    int add() { }        // Override at compile time
};

class MathComputerDerived : public MathComputer
{
public:
  int computerResult(int x, int y)
  {
      cout << "Override Virtual Function at run time" << endl;
      return (x + y);
  }  
  int add(int x, int y) 
  {
  cout << "Overload function in base class at compile time" << endl;
  return x + y;
  }
};

                     //function pointer
int sum(int i, int j) { return i + j; }

template <typename Functype>  //template function
int doMath (int x, int y, Functype func )
{
    cout << "Function pointer template " << endl;
    return func(x, y);
}

int add(int(*funcptr)(int, int), int i, int j)
{
    cout << "Function pointer " << endl;
    return funcptr(i, j);    
}
int main()
{
    int (*fp1)(int a, int b);
    fp1 = sum;       
    cout << doMath(1, 2, fp1) << endl;  //function pointer
    cout << add(fp1, 1, 2) << endl;
    
    MathComputerDerived mc;  //virtual function in derived class (Overload at run time)
    cout << "Override virtual function from derived class = " << mc.computerResult(1, 2) << endl;
    cout << "Overload function " << mc.add(3, 4) << endl; //overload function at compile time
    MathComputer *m = &mc;  //virtual function in based class
    cout << "Override virtual function from based class = " << m->computerResult(2, 3) << endl;
    
    cout << "Function object or Functor = " << mc(9, 2) << endl;  //functor
    
}