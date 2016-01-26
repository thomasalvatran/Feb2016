// http://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php 
// Not Working need change move segmentic &&
#include <iostream>
#include <thread>
#include <string>
#include <unistd.h> //sleep(1)

using namespace std;
//void thread_function(string s)    //pass by value
void thread_function(string& s)  //pass by ref
// void thread_function(string&& s)    //move segmentic take rvalue reference &&
{
    cout << "Thread function:  " << s << endl;
    s = "Hello from Main...";
}

int main()
{
    string s = "Hello from Thread";
    // thread t(&thread_function, "Hello from thread ");  //passing string to thread function
    thread t(&thread_function, ref(s));
    // thread t(&thread_function, move(s));
    sleep(2);  //wait for s string change from thread function
    cout << "Main thread: " << s << " ID " << this_thread::get_id() << " " << t.get_id()<< endl;
    cout << thread::hardware_concurrency() << endl;
    t.join();
    
    return 0;
}