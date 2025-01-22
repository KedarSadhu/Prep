#include "Logger.h"

void fun();

int main()
{
    Logger *lPtr1 = new Logger();
    lPtr1->Log("In Main :: Log msg1");

    fun();
    return 0;
}