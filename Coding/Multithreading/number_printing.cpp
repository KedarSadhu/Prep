#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

//using namespace std;

const int MAX_NUM = 10;
std::mutex mutex;
int current_num = 1;

void printNum(int thread_id) {
    while (true) 
    {
        std::this_thread::sleep_for (std::chrono::seconds(2));
        mutex.lock();
        if (current_num > MAX_NUM) 
        {
            mutex.unlock();
            break;
        }

        std::cout << "Thread " << thread_id << " prints " << current_num << std::endl;
        ++current_num;
        mutex.unlock();
    }
}

int main() {
    const int NUM_THREADS = 2;
    std::thread threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i] = std::thread(printNum, i + 1);
    }
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }
    return 0;
}
