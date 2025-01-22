#include<iostream>
using namespace std;

int main(void)
{
    int arr[4] = {10,20,30,40};
    int end = 3;
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
        if(i<=end)
        {
            temp  = arr[i];
            arr[i] = arr[end];
            arr[end] = temp;
            end--;
        }
    }
    
    for(int i =0;i<4;++i)
    {
        cout<<arr[i]<<"\t";
    }

    exit(0);
}