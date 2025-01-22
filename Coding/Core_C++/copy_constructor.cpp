#include<iostream>
using namespace std;

class Demo
{
    int mNo1;
    int mNo2;

    public:

    Demo(int no1 ,int no2)
    {
        mNo1 = no1;
        mNo2 = no2;
    }

    Demo(Demo &refObj)
    {
        cout<<"In copy constructor"<<endl;
        mNo1 = refObj.mNo1;
        mNo2 = refObj.mNo2;
    }

    Demo(Demo &refObj, int no)
    {
        cout<<"In copy constructor with 1 parameter"<<endl;
        mNo1 = refObj.mNo1 + no;
        mNo2 = refObj.mNo2 + no;
    }

    void Display()
    {
        cout<<"mNo1 :: "<<mNo1<<"\t mNo2 :: "<<mNo2 <<endl;
    }
};

int main()
{
    Demo obj1(10,20);   //parameterized
    obj1.Display();
    
    Demo obj2(obj1);    //copy constructor
    obj2.Display();

    Demo obj3(obj2,30);   //copy constructor with parameter
    obj3.Display();

    Demo obj4 = obj3;      //copy constructor
    obj4.Display();
    
    return 0;
}