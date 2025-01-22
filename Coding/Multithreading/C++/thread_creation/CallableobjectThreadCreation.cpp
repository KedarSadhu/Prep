#include <iostream>
#include <thread>

class MyFunctor
{
public:
    void operator()() {
        std::cout << "functor\n";
        for(int i = 0;i<10;i++)
        {
          std::cout<<i<<std::endl;
        }
    }
};

int main()
{
    MyFunctor fnctor;
    std::thread t(fnctor);
    std::cout << "main thread\n";
    t.join();
    return 0;
}