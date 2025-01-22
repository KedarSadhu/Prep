#include<iostream>
using namespace std;
//requirement : demo1 la demo 2cha sagla accessible rahayala hava

class demo1
{
    public:
    demo1()
    {
        cout<<"Inside demo1()\n";
    }

    void gun();

};
class demo2
{
    int i;

    void fun()
    {
        cout <<"in demo2 private fun()\n";
    }
    friend class demo1; //demo2 mhnla demo1 maza friend ahe tyala mazyat access karu de maza use karun  

    public:
    demo2()
    {
        cout<<"in demo2()\n";
        i=20;
    }
};

void demo1::gun()
   {
        cout<<"In gun()"<<endl;
        demo2 obj1;
        obj1.fun();
        cout<<"obj1.i = "<<obj1.i<<endl;
    }

int main(void)
{
    demo1 obj;
    obj.gun();
    exit(0);
}