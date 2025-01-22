#include<iostream>
using namespace std;

int main(void)
{
    int no = 0;
    cout<<"Enter no : ";
    cin >> no;
    int rem ,revNo =0;
    while(no != 0)
    {
        rem = no%10;
        no = no/10;
        revNo = (revNo * 10) + rem;
    }

    cout<< "reverse no is :: "<<revNo<<endl;
    exit (0);
}