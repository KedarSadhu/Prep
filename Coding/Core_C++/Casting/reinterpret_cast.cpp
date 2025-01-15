#include<iostream>

using namespace std;

int main()
{
    int * p = new int(65);

    char *c = reinterpret_cast<char *>(p);

    cout<<*c<<endl; //A
    cout<<*p<<endl; //65

    return 0;
}