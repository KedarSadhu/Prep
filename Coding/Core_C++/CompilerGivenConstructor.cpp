#include<iostream>

using namespace std;

class demo
{
    int iNo;

    public:
    
    void fun()
    {
        iNo = 10;
        cout << "In fun()" <<endl;
    } 
};

class demo2
{
    public:
    demo2(int iNo)
    {
        cout<<"In parametrized constructor : iNo = "<<iNo<<endl;
    }
};

int main()
{
    demo obj1;//worked
    demo obj2(obj1);//worked
    demo obj3 = obj2;//worked

    obj1.fun();
    obj2.fun();
    obj3.fun();

    //demo obj4(10); //not given by compiler
    
    demo2 dobj1(10);
    //demo2 dobj2; //apan parameterized dila tr to tyacha kuthlach nahi det    
    return 0;
}