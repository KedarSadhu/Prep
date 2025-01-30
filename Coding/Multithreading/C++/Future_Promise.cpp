#include<iostream>
#include<thread>
#include<future>

typedef unsigned long long int ull;
using namespace std;

/*
    promise:
        Used to set values or expectation

    future:
        1.used to get values from promise
        2.Ask promise if the value is available
        3.wait for the promise
*/

void findOdd(promise<ull>&&OddSumPromise,ull start,ull end)
{
    ull OddSum = 0;
    for (ull i = start; i < end;i++)
    {
        if(i&1)
            OddSum = OddSum + i;
    }

    OddSumPromise.set_value(OddSum);
}

int main()
{
    ull start = 0;
    ull end = 100000;

    promise<ull> Oddsum;
    future<ull> OddFuture = Oddsum.get_future();

    cout << "Thread created !!" << endl;
    thread t1(findOdd, move(Oddsum), start, end);

    cout << "Waiting for result !!!" << endl;

    cout << "Odd sum :" << OddFuture.get()<<endl;

    cout << "Task Completed ...." << endl;

    t1.join();

    return 0;
}