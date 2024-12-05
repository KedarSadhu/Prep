#include<iostream>
using namespace std;

class base
{
    public:
    int i;

    base()
    {
        i = 10;
        cout<<"In base :: i = "<< i << endl;
    }
};

class derived1 : public base
{
    public:
    derived1()
    {
        i =20;
        cout<<"In derived1 :: i = " << i <<endl;
    }
};

class derived2 : public base
{
    public:
    derived2()
    {
        i =30;
        cout<<"In derived2 :: i = " << i <<endl;
    }
};

class derived3 : public derived1,derived2
{
    public:
    derived3()
    {
        cout<< "In derived3 :: i = " << i <<endl; // error i is ambiguous  derived1,derived2 madhe i chi copy
    }
};
int main(void)
{
    derived3 dobj3;
  
    return 0;
}