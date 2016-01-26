 // You tube lambda expression in  C++ Bradley Needham
 #include <iostream>
 #include <vector>
 #include <algorithm>  //count_if
 #include <iomanip>
 using namespace std;
 
 struct isOdd
 {
     bool operator()(int x)
     {
         return x % 2;
     }
 };
 bool isEven( int x)
 {
 		return !(x % 2);
 }
 
class isMultipleOf
{
	int m_multi;
public:
	isMultipleOf(int multi) : m_multi(multi) {}
	bool operator()(int x)
	{
		return !(x % m_multi);
	}
};
class SumUp
{
	int &m_sum;
public:
  SumUp(int &sum) : m_sum(sum) {}
  void operator()(int x) { m_sum += x; }
	
};
int main()
{
 
 vector<int> col = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 25};
 {
 size_t c = count_if(col.begin(), col.end(), isOdd());  //struct overload operator()
 size_t c1 = count_if(col.begin(), col.end(), isEven);  //using function
 cout << "Integers that are odd: " << c << " and Even: "<< c1 << endl;
 }
 int multi = 2;
 {
 size_t c = count_if(col.begin(), col.end(), [](int x){ return !(x % 2); }); 
 cout << "Integers that are even: " << c << endl; 
 }
 {
 size_t c = count_if(col.begin(), col.end(), isMultipleOf(multi) ); 
 cout << "Integers that are multiple of: " << c << endl; 
 }
 {
 size_t c = count_if(col.begin(), col.end(), [multi](int x){ return !(x % multi); } ); //capture multi
 cout << "Integers that are multiple of: " << c << endl; 
 }
 {
 size_t c = count_if(col.begin(), col.end(), [=](int x){ return !(x % multi); } ); //capture multi
 cout << "Integers that are multiple of: " << c << endl; 
 }
 {
 int sum = 0;
 for_each(col.begin(), col.end(), SumUp(sum) ); //capture multi
 cout << "Sum1 is: " << sum << endl; 
 } //end of scope so variable can be resused
 {
 int sum = 0;
 int *sum1 = &sum;
 for_each(col.begin(), col.end(), [&sum](int x) { sum += x; } ); //capture sum by value is copy from sum 
 cout << "Sum2 is: " << sum << endl; 														//problem
 }
 {
 int sum = 0;
 for_each(col.begin(), col.end(), [=](int x) mutable { sum += x; } ); //capture sum by value is copy from sum 
 cout << "Sum3 is: " << sum << endl; 
 }
 {
 size_t c;
 c = count_if(col.begin(), col.end(), [](int x) ->bool   //landa more then 1 line specify return type ->
	 { 
	 	bool odd = x % 2;
	 	cout << x << " is " << (odd ? "odd" : "event") << endl;
	 	return odd; 
	 } 
 ); //capture sum by value is copy from sum 
 cout << "Number of odd integers " << c << endl;  //from ->bool
 }
 { //call lambda to print
 double x = 12.12;
 cout << [&x]() -> double { return x * 2; }() << endl;  //return type if many line in lambda
 cout << setprecision(4) << x * 2 << endl;
 }
 return 0;
} 