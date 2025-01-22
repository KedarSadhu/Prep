#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int no;
    cout<<"Enter no : ";
    cin>>no;

    int digit = 0;
    int decimal =0;
    int i = 0;

    while(no !=0)
    {
       digit = no % 10;
       decimal = digit * pow(2,i) + decimal;
       no= no/10;
       ++i; 
    }

    cout <<"Decimal :"<<decimal <<endl;
    exit(0);
}