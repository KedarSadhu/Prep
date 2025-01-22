#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex mutex_;
condition_variable condVar;

void doTheWork()
{
  cout << "Consumer : Processing shared data." << endl;
}

void waitingForWork()
{
    cout << "Consumer : Waiting for work." << endl;
    unique_lock<mutex> lck(mutex_);
    condVar.wait(lck);
    doTheWork();
    cout << "Consumer : Work done." << endl;
}

void setDataReady()
{
    this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Producer : Data is ready."  << endl;
    condVar.notify_one();
}

int main(){

  cout << endl;

  thread t1(waitingForWork);
  //_sleep(10);
  thread t2(setDataReady);

  t1.join();
  t2.join();

  cout << endl;
  
}