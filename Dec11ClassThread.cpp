// http://stackoverflow.com/questions/31417389/use-member-function-for-stdthread-with-stdrefthis-fails-to-compile
#include <thread>
#include <iostream>
using namespace std;
class Worker
{
public:
  // Worker() : m_worker(&Worker::doWork, std::ref(*this), 1) {}
  // std::string s = "Hello from Thread";
  Worker(string a) : m_worker(&Worker::doWork, this, a) {}
  std::thread m_worker;

  void doWork(string a) { std::cout << a << std::endl; }
};

int main(int argc, char* argv[]) {
  Worker k("Hello World");
  k.m_worker.join();  //terminate called without an active exception forget to join main thread. exception forget to join
}