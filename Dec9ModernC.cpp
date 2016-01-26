//Modern C++ youtube.com A tout of Modern C++
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional> //function
#include <type_traits> //static_insert
#include <memory> //unique_ptr

using namespace std;

struct Address
{

};

struct Person{  //own type not build in type
    string name;
    int age;
    Address address;
public:
    explicit Person(const Address& address) : address(address){}
    explicit Person(const string name, const int age):
    name(name), age(age){}
};

struct Exchange
{
    int count;
    float rates[2];
    Exchange(initializer_list<float> r)
    {
        if (r.size() < 2) return;
        auto i = r.begin();
        rates[0] = *i;
        i++;
        rates[1] = *i;
    }
};

template<typename T, typename U>
auto add(T t, U u) //->decltype(t+u)
{
    return t + u;
}

auto meaning_of_life() //->int
{
    return 42;
}

class Animal
{
protected:
    int legs = 4; //old C++ const int legs
public:
    explicit Animal(int legs) : legs(legs) {}
    virtual int walk(int steps)
    {
        return steps * 20;
    }
};

class Human : public Animal
{
 public:
    Human() : Animal(2) {}   //derived from Animal calls base ctor ****
//    Human(const Human&) = delete; //avoid generate automatic
//    int walk(int steps) override;
    int walk(int steps)
    {
        return steps * 10;
    }
};
    enum oldColor
    {
        Red, Green, Blue
    };
    oldColor oc = Green;
    int g = oc;
    enum class NewColor
    {
       Red, Green, Blue, Magenta
    };
    NewColor nc = NewColor::Magenta;
//    int m = NewColor::Magenta;  //cannot convert NewColor to int
    NewColor m = NewColor::Magenta;

template<typename T, size_t Size>
class Values
{
    static_assert(Size > 1, "Use a scalar");
    T values[Size];
};
//Variadic functions numbers of type feeds into the template Dec4DynamicArguments.cpp
auto sum() { return 0; }
template <typename H, typename...T>  //...ellipses
auto sum(H h, T...t) //-> decltype(h+sum(t...))   //C++14 need decltype
{
    return h+sum(t...);
}

auto sum_product(double a, double b)
{
    return make_pair(a + b, a *b);
}

class Person1
{
    Address* address;
    Person1(Address* address) : address(address){}
    ~Person1()
    {
        if (address)
            delete address;
    }
};


class Address_1
{
public:
    Address_1(){} //ctor
    Address_1(const Address_1&) { cout <<  " Address copies " << endl; } //ctor
    int house_number;
    string city;
    string postcode;
};

Address_1 create_address(int house, string postcode)
{
    Address_1 address{};
    address.house_number = house;
    address.postcode = postcode;
    return address;
}

unique_ptr<Address_1>  create_address_smart(int house, string postcode)
{
    auto a = make_unique<Address_1>();
    a->house_number = house;
    a->postcode = postcode;
    return a;
}

class Person_1
{
public:
//    unique_ptr<Address_1> address;
    shared_ptr<Address_1> address;
    Person_1()
    {
        address = make_unique<Address_1>();  //unique address
    }
};
//rvalue
string getName()
{
    return "Dmitri";
}

void printName(const string& name)  //C++ reference
{
    cout << "Ordinary reference " << name << endl;
}

void printName(string&& name)
{
    cout << "Rvalue reference " << name << endl;
}

int main()
{
    string name1 = getName();
    const string& name2 = getName(); //remove const fail
//    name2 = "abc";  //fail name2 is const

    string name3 = "test";          //THIS IS MY TROUBLE...???
    const string& name_3 = "test1";
    cout << name_3 << endl;

    string&& name4 = getName();  //rvalue reference
    name4 = "Jack";
    cout << name4 << endl;

    string j{"john"};
    printName(getName());  //&& rvalue how ???
    printName(j);

    {
        auto my_address = create_address(23, "SO17");
        auto my_address2 = create_address_smart(23, "SO17");

//        unique_ptr<Address_1> a;
        shared_ptr<Address_1> a;
        {
            Person_1 p;
            p.address->city = "London";
            a = p.address;
        }
    }

    {//variadic
        cout << "Sum = " << sum(1, 2.4, 3) << endl;

//        auto values = sum_product(3, 4);
//        auto s = get<0>(values);
        float s;
        tie(s, ignore) = sum_product(3, 4);
        cout << "sum " << s << endl;
    }

    {
        Values<int, 3> stuff;

    }
    {
        vector<int> v {1, 2, 3};
        for_each(v.begin(), v.end(), [](int x){
            cout << x << " ";
        });
        cout << endl;
        for_each(begin(v), end(v), [](int x){
           cout << x << " ";
        });
        cout << endl;
        for(int a : v)
        {
            cout << a << " ";
        }
        cout << endl;
        for(int& a: v)
        {
            a *= a;
            cout << a << " ";
        }
        cout << endl;
        for(int x : {1, 2, 3})
        {
            cout << "x " << x << endl;
        }
        cout << endl;
        map<string, int> histogram;
        for (const auto& kvp: histogram)
        {
            cout << kvp.first << " kvp " << kvp.second << endl;
        }
    }
    {
        vector<int> scores {8, 2, 4, 3};
        for_each(begin(scores), end(scores), []( int n) -> float
        {
            cout << n << endl;
            return n;
        });
        int zero = 0;
        auto is_positive = [zero](int n){ return n > zero; };
        cout << boolalpha << is_positive(2) << endl;
    }
    {

    }
//    auto fib = [&fib](int x) { return x < 2 ? 1 : fib(x -1) + fix(x - 2); };
    function<int(int)> fib = [&fib](int x) { return x < 2 ? 1 : fib(x -1) + fib(x - 2); };
    cout << "fib =" << fib(8) << endl; //so to use it

    Human h;
    Human h2{ h };//copy
    cout << "walk = " << h2.walk(1) << " " << h.walk(2) << endl;

    Exchange e{10, 2, 3};  //legal value 1 assign to count and 2, 3 to rates
    Exchange e1{100.10, 200.20};    //count  == 1 and 1st element of array == 2
    cout << e1.count << " " << e1.rates[0] << " " << e1.rates[1] << endl;

    cout << add(2, 2.5) << endl;
    cout << add(string("Hello, "), "world") << endl; //string + char

    vector<double> value;
    typedef decltype(value.begin()) dvi;
    typedef decltype(42) myint;
//    myint = 1; //FAIL expected unqualified id before = token but it is ok myint(1)
    cout << "myint =" << myint(1) << endl;
    typedef decltype(add(2, 2.5)) qtype;
    cout << qtype(2222) << endl;

    int a = 1;
    int n{4}; //more powerful easy to initialize type
    string s{ "foo" };

    vector<int> values = {1, 2, 3};

    vector<int> values0;
    values0.push_back(1);

    vector<int> values1{1, 2, 3};  //new modern

    // map<string, string> capitals = {  OK without operator =
    map<string, string> capitals {
      {"UK", "London"}
    };
    Person p{"tom", 12};

    Person person(Address());  //like function
    Person person1{Address()}; // uniform initialization  this is constructor
    {
        auto a = 12.11;
        auto c =  "hello";
        auto d = { 1, 2, 3 };
        cout << a << endl;
        decltype(a) x = 2;


        map<string, vector<double>> ticks;
        auto itt = ticks.begin();

        map<string, vector<double>>::iterator it = ticks.begin();

        cout << meaning_of_life() << endl;
    }

}
