#include<iostream>

using namespace std;

class demo
{
    int iNo;
  
    public:
    demo()
    {
        cout<<"Demo()"<<endl;
    }

    //demo(int i)
    explicit demo(int i)
    {
        iNo = i;
        cout<<"Demo(int) :: "<< iNo <<endl;
    }

    void print()
    {
        cout<<"iNo = "<<iNo<<endl;
    }
};

void fun(demo d)
{
  d.print();
}

int main()
{
    demo d1(20);
    demo d2 = 30;   //allowed if demo(int i) is used --> 30//he allow kasa ky zala ?? implcitly constructor call zalya mule he allow zala
    //he asa behaviour avoid karnya sathi explicit key word use kartat jyane asla code complie ch hot nahi.
    // Error if explicit demo(int i) is used --> avoid implicit casting

    fun(d1);        //20
    fun(40);       // Error if explicit demo(int i) is used --> avoid implicit casting
    //allowed if demo(int i) is used --> implicit call jato parameterized constructor la        40

    return 0;
}