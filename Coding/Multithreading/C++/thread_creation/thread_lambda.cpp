#include <iostream>
#include <thread>

int main()
{
    std::thread t([]()
    {
        std::cout << "thread function\n";
    }
    );
    std::cout << "main thread\n";
    t.join();     
    return 0;
}