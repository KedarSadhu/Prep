#include<iostream>
using namespace std;

class demo1
{
    int i;

    void fun();
    public:
    demo1()
    {
        i=10;
    }
    void gun();
};


class demo2
{
    friend void demo1::gun();   // Demo2 sangtoy ki demo1 madhla gun he function maza friend ahe tyala aat yeudya
                                //ani maza private access karu dya maza use karun
    int j;

    public :
    demo2()
    {
        j=20;
    }

};

void demo1 ::fun()
{
    cout<<"In fun()"<<endl;
}

void demo1:: gun()
{
    demo2 obj;

    cout<<obj.j<<endl;
    fun();
}

int main(void)
{
    demo1 obj;
    obj.gun();
    exit(0);
}