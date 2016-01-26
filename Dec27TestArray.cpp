//http://en.wikipedia.org/wiki/Copy_constructor
#include <iostream>
#include <memory>
using namespace std;

class Array
{
public:
    int size;
    int* data;

    Array(int sz) : size(sz), data(new int[sz]) {}
    ~Array() { delete [] this->data; cout << "Dtor" << endl; }
    Array(const Array& other) : size(other.size), data(other.data) { cout << "Ctor 1" << endl; } //shallow copy by compiler
    Array(Array& other): size(other.size), data(new int[other.size]) //deep copy overload without const 
    {
        copy(other.data, other.data + other.size, data);
        cout << "Ctor 2" << endl; 
    }
};

int main()
{
    Array first(20);
    first.data[0] = 25;
    {
		Array copy = first;
		std::cout << first.data[0] << " " << copy.data[0]
			<< std::endl;
	} // (1)
	first.data[0] = 10; // (2)
    cout << first.data[0] << endl;
    //new C11 standard without deep copy as above
    shared_ptr<int> test(new int[10]);
    test.operator->()[0] = 1212;
    {
        shared_ptr<int> t = test;
        cout << test.operator->()[0] << " " << t.operator->()[0] << endl;
    }
    cout << test.operator->()[0] << endl;
}