#include<iostream>
using namespace std;

int main()
{
    int iNo = 10;

    cout<<"iNo = "<< iNo <<endl;

    // It performs compile-time type conversion and 
    // is mainly used for explicit conversions that are 
    // considered safe by the compiler.
    double dNo = static_cast<double>(iNo);

    cout<<"dNo = "<< dNo <<endl;

    cout<<"typeid(iNo).name() = "<<typeid(iNo).name()<<endl;
    cout<<"typeid(dNo).name() = "<<typeid(dNo).name()<<endl;

    return 0;
}