#include<iostream>

using namespace std;

class demo
{
    int iNo;

    public:
    demo()
    {
        iNo = 10;
        cout<< "In default constructor : iNo = "<< iNo <<endl;
    }

    demo(int n)
    {
        iNo = n;
        cout << "In parameterized constructor : iNo = "<< iNo <<endl;
    }

    demo(demo &refObj)
    {
        iNo = refObj.iNo;
        cout<<"In Copy constructor : iNo = "<< iNo <<endl;
    }

    ~demo()
    {
        cout<<"In destructor"<<endl;
    }
};

int main()
{
    demo obj1;  //In default constructor : iNo = 10
    demo obj2(20); //In parameterized constructor : iNo = 20
    demo obj3(obj1); //In Copy constructor : iNo = 10
    demo obj4 = obj2; //In Copy constructor : iNo = 20

    /*
        Compiler by default copy assignment operator deto 

        When to Define a Custom Assignment Operator:
            If your class manages dynamic memory or other resources, 
            you should explicitly define a copy assignment operator to handle deep copying 
            and resource management properly.
            
            You can follow the Rule of Three in C++98: 
            if your class needs a custom destructor, copy constructor, or copy assignment operator, 
            it likely needs all three.

        In modern C++ (C++11 and later), with the introduction of move semantics, 
        you might also consider defining a move assignment operator to optimize resource transfers.
    
    */

    return 0;
}