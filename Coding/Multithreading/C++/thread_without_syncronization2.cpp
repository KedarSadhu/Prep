#include<iostream>
#include<thread>

using namespace std;

int g_iNo;

void thread_func(int n)
{
    int local;
    for(int i = 0; i < n; i++)
    {
        local = g_iNo;
        local++;
        g_iNo = local;
    }
}


int main(void)
{
    thread th1(thread_func,10000000);
    thread th2(thread_func,10000000);
    th1.join();
   
    th2.join();

    cout<<g_iNo<<endl;
    exit(0);
}