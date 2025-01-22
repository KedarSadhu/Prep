#include "Logger.h"

void fun1();
void fun2();


int main()
{
    Logger *lPtr1 = Logger::getLogger();
    lPtr1->Log("In Main :: Log msg1");

    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();
    return 0;
}