#include<iostream>

using namespace std;

/*The const_cast operator is used to modify the const or 
volatile qualifier of a variable. It allows programmers to 
temporarily remove the constancy of an object and make modifications. 
Caution must be exercised when using const_cast, 
as modifying a const object can lead to undefined behavior.*/

int main()
{
    const int iNo = 5;

    const int *p = &iNo;

    cout<<"iNo = "<<iNo<<endl;  //5
    cout<<"*p = "<<*p<<endl; //5
    cout<<"p = "<<p<<endl;//0x5ffe8c
    cout<<"&iNo = "<<&iNo <<endl;//0x5ffe8c

    int *ptr = const_cast<int*>(p);
    *ptr = 10;

    cout<<"after casting ::"<<endl;
    cout<<"iNo = "<<iNo<<endl;//5
    cout<<"*p = "<<*p<<endl;//10
    cout<<"p = "<<p<<endl; //0x5ffe8c
    cout<<"ptr = "<<ptr<<endl;//0x5ffe8c
    cout<<"*ptr ="<<*ptr<<endl; //10
    return 0;
}