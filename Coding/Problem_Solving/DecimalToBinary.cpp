#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int no;
    cout<<"Enter no : ";
    cin>>no;

    int bit = 0;
    int binary =0;
    int i = 0;

    while(no !=0)
    {
       bit = no & 1;
       binary = bit * pow(10,i) + binary;
       no= no>>1;
       ++i; 
    }

    cout <<"Binary :"<<binary <<endl;
    exit(0);
}