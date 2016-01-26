// thread::get_id / this_thread::get_id
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::thread::id, std::this_thread::get_id
#include <chrono>         // std::chrono::seconds
using namespace std;

std::thread::id main_thread_id;

int main() {
    main_thread_id = std::this_thread::get_id(); // gotcha!
    cout << main_thread_id << endl;
    /* go on */
}