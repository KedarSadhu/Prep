#include<iostream>
#include<thread>


using namespace std;

void thread_func(int n)
{
    for(int i = 0; i < n; i++)
    {
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