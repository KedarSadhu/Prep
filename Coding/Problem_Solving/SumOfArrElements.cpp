#include<iostream>
using namespace std;

int main(void)
{
    int arr[5] ={-1,14,15,46,99};
    int sum = arr[0];
    
    for(int i = 1;i<5 ;++i)
    {
        sum = sum +arr[i];
    }
    cout<<"Sum = "<<sum <<endl;
    exit(0);
}