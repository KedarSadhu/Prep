#include<iostream>
using namespace std;

//static datamembers are not part of object they are stored in static section
class base
{
    public: //access specifire rules are applicable to static 
    static int i;
    int j;

    static void gun()
    {
        i++;
        cout<<"i = " << i;//21
        //j = i;    //cant use j as gun function dont have this ptr
        //cout<<j;
    }
};
int base::i =20;

int main(void)
{
    cout<<"sizeof(base) :: "<<sizeof(class base)<<endl;  //4
    cout<<"i = " << base::i<<endl;//20
    base::gun();
    return 0;
}