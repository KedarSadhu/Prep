//Fibonacci series --> 0,1,1,2,3,5,8,13,21
#include<iostream>

using namespace std;

int main(void)
{
    int no1 = 0;
    int no2 = 1;

    cout<<no1<<","<<no2 <<",";

    for(int i = 1;i <= 10 ; i++)
    {
        int nextNo = no1 + no2;//1= 0+1
        cout<< nextNo << "," ;
        no1 = no2;
        no2 = nextNo;
    }

    exit(0);

}