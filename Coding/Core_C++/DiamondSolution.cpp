#include<iostream>
using namespace std;

#pragma pack(1) //padding off
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

class derived1 : public virtual base
{
    public:
    derived1()
    {
        i =20;
        cout<<"In derived1 :: i = " << i <<endl;
    }
};

class derived2 : public virtual base
{
    public:
    derived2()
    {
        i =30;
        cout<<"In derived2 :: i = " << i <<endl;
    }
};

class derived3 : public derived2,derived1
{
    public:
    derived3()
    {
        cout<< "In derived3 :: i = " << i <<endl;  //derived2,derived1 yanchya sequence nusar i chi value
    }
};
int main(void)
{
    derived3 dobj3;
    cout<<"sizeof(class base) :: " <<sizeof(class base) <<endl; // 4
    cout<<"sizeof(class derived1) :: " <<sizeof(class derived1) <<endl; //12 (i,vptrd1) 
    cout<<"sizeof(class derived2) :: " <<sizeof(class derived2) <<endl; // 12(i,vptrd2)

    cout<<"sizeof(dobj3) :: " <<sizeof(dobj3) <<endl; // 20 -> (i,vptrd1,vptrd2)
  
    return 0;
}