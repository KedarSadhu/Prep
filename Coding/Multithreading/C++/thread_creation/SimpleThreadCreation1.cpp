#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function\n";
    for(int i = 0;i<10;i++)
    {
        std::cout<<i<<std::endl;
    }
}

int main()
{
    std::thread t(thread_function);   // t starts running
    std::cout << "main thread\n";
    t.join();   // main thread waits for the thread t to finish
    std::cout << "t joined with main" <<std::endl;
    return 0;
}