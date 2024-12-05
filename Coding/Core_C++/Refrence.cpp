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
        cout << "this->ino1 = " << ino1 << "\tthis->refno = " << refno << endl;
        cout << "&this->ino1 = " << &ino1 << "\t&this->refno = " << &refno << endl;
    }

};

int main(void)
{
    demo obj;

    cout << sizeof(obj) << endl;

    int ino1 = 10;
    int ino2 = 20;

    int &refno = ino1;
    cout << "ino1 = " << ino1 <<"\trefno = " << refno << endl;
    refno = ino2;

    cout << "ino1 = " << ino1 << "\tino2 = " << ino2 << "\trefno = " << refno << endl;
    cout << "&ino1 = " << &ino1 << "\t&ino2 = " << &ino2 << "\t&refno = " << &refno << endl;

    return 0;
}