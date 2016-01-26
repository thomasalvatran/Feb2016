#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    for ( double x = 0.0; x < 1 ; x+= (double)1/15, i++) // x must be double
      cout << i << " " << x  << endl;
      
      int x = 15;
      cout << "x = " << x << " " << i << endl << endl;
      
    do
    {
      i--;
      cout << "x = " << x << " " << i << endl;
    }
    while(x--> 0);
    return 0;
}