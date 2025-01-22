#include<iostream>
using namespace std;

int main(void)
{
    int arr[5] = {100,1,1,104,35};

    int min = arr [1];
    int max = arr [1];
    for(int i =0;i<5;++i)
    {
        if(arr[i]< min)
            min = arr[i];
        if(arr[i]>max)
            max = arr[i];
    }
    cout<<"min :: " <<min<<endl;
    cout<<"max :: " <<max<<endl;

  
    exit(0);
}