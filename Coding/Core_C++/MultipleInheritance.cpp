#include<iostream>
using namespace std;

class base1
{
    public: 
    int i;

    base1()
    {
        i = 10;
        cout<<"In base1 \n";
    }
};

class base2
{
    public: 
    int i;

    base2()
    {
        i = 20;
        cout<<"In base2 \n";
    }
};

class derived : public base1,base2 //multile inheritance //in this case jo pehila class lihila tyacha pahila constructor call hoil 
{
    public:
    int k;
    derived()
    {
        //k = i; // yane ambiguty ali ki i base1 madhla ki base2 madhla 
        k = base1::i;   //resolving ambiguty
        cout<<"In derived :: k = "<<k<<endl;
    }
};

int main(void)
{
    derived dObj;
    return 0;
}