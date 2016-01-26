#include <iostream>
using namespace std;

class PrintData
{
  public:
  void print(int i)
  {
      cout << "Print int " << i << endl;
  }
  void print(double d)
  {
      cout << "Print double " << d << endl;
  }
  void print(float f)
  {
      cout <<  "Print float " << f << endl;
  }
  void print(const char *c)
  {
      cout << "Print character " << c << endl;
  }
};

int main()
{
    PrintData pt;
    pt.print(100);
    pt.print(22.00);
    pt.print(24.24);
}