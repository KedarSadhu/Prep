#include<iostream>
using namespace std;

#pragma pack(1)
class demo
{
    int ino1;
    int &refno;

    public:
    demo():refno(ino1)
    {
        ino1 = 90;
        cout << "this->ino1 = " << ino1 << "\tthis->refno = " << refno << endl; //90 90
        cout << "&this->ino1 = " << &ino1 << "\t&this->refno = " << &refno << endl;//0x307cbffdec 0x307cbffdec
    }

};

int main(void)
{
    demo obj;

    cout << sizeof(obj) << endl;    //12

    int ino1 = 10;
    int ino2 = 20;

    int &refno = ino1;
    cout << "ino1 = " << ino1 <<"\trefno = " << refno << endl;  //10 10
    refno = ino2;

    cout << "ino1 = " << ino1 << "\tino2 = " << ino2 << "\trefno = " << refno << endl;  //20 20 20 
    cout << "&ino1 = " << &ino1 << "\t&ino2 = " << &ino2 << "\t&refno = " << &refno << endl; //0x307cbffde8 0x307cbffde4 0x307cbffde8

    //int &ref1 = 10;   //not allowed
    const int &ref2 = 10; //allowed

    return 0;
}