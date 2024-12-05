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
        cout<<"i = " << i;
        //j = i;    //cant use j as gun function dont have this ptr
        //cout<<j;
    }
};
int base::i =20;

int main(void)
{
    cout<<"sizeof(base) :: "<<sizeof(class base)<<endl;  //1
    cout<<"i = " << base::i<<endl;
    base::gun();
    return 0;
}