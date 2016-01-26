#include <iostream> //http://en.wikipedia.org/wiki/Copy_constructor
using namespace std; 

class Array {
public:
    int size;
    int* data;   //dynamic memory allocation
 
    explicit Array (int size) : size (size), data (new int[size]) {} //contructor
	 Array(const Array& copy) : size(copy.size), data(new int[copy.size]) //copy constructor
	{
 		std::copy(copy.data, copy.data + copy.size, data);    // #include <algorithm> for std::copy
	} 
    ~Array() 
    {
        delete[] data;
    }
};

int main()
{
    Array first (20);
    first.data[0] = 25; //reserved 
 
    {
        Array copy = first;  //copy 
        std::cout << first.data[0] << " " << copy.data[0] << std::endl;
 
    }    // (1)
 
  first.data[0] = 10;    // (2)
   return 0;
}