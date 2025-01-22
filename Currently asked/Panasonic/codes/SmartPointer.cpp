#include<iostream>
using namespace std;

class MyClass 
{ 
    private: 
        int* ptr; 

    public: 
        MyClass(int val) 
        { 
            ptr = new int(val); 
        }
        
        ~MyClass() 
        { 
            delete ptr; 
        }
};

/*Refactor above code using smart pointer*/

#include <iostream>
#include <memory> // For std::unique_ptr
using namespace std;

class MyClass 
{ 
    private: 
        unique_ptr<int> ptr; // Use smart pointer instead of raw pointer

    public: 
        // Constructor
        MyClass(int val) : ptr(make_unique<int>(val)) 
        {
            // Automatically manages memory, no need for explicit new
        }

        // Destructor
        ~MyClass() 
        { 
            // No need for explicit delete; std::unique_ptr handles it automatically
        }

        // Example member function to get the value
        int getValue() const 
        {
            return *ptr;
        }
};

int main()
{
    MyClass obj(42);
    cout << "Value: " << obj.getValue() << endl; // Output: Value: 42
    return 0;
}
