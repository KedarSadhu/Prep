#include<iostream>
#include<thread>
#include <mutex>

using namespace std;
mutex g_display;

void thread_func(int n)
{
    for(int i = 0; i < n; i++)
    {
        lock_guard<mutex>lock(g_display);
        cout<<"thread_id = "<<this_thread::get_id()<<"\ti = "<<i<<endl;
    }
}


int main(void)
{
    thread th1(thread_func,10);
    thread th2(thread_func,20);
    th1.join();
   
    th2.join();
    exit(0);
}