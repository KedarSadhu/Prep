#include<iostream>
#include<thread>
#include<future>

using namespace std;
typedef unsigned long long int ull;

ull FindOddSum(int start,int end)
{
    ull OddSum = 0;
    for (int i = start; i < end;i++)
    {
        if(i & 1)
            OddSum = OddSum + i;
    }

    return OddSum;
}

int main(void)
{
    ull start = 0;
    ull end = 100000;

    // cout << "Thread created with deferred policy :" << endl;
    // future<ull> Oddsum = async(launch::deferred, FindOddSum, start, end); //lazy evaluation

    cout << "Thread created with async policy :" << endl;
    future<ull> Oddsum = async(launch::async, FindOddSum, start, end);  //eager evaluation

    cout << "Waiting for result !!!" << endl;
    cout << Oddsum.get() << endl;
    cout << "Completed ..." << endl;
    return 0;
}