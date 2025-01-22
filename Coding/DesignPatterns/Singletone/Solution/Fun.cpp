#include "Logger.h"

void fun1()
{
    Logger *lptr2 = Logger::getLogger();
    lptr2->Log("In Fun1 :: log msg2");
}

void fun2()
{
    Logger *lptr2 = Logger::getLogger();
    lptr2->Log("In Fun2 :: log msg2");
}