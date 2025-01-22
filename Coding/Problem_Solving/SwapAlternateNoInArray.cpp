/*
case 1 -- odd
    input - {10,20,30,40,50}
    output - {20,10,40,30,50}
case 2 -- even
    input - {10,20,30,40}
    output - {20,10,40,30}
*/

#include<iostream>
using namespace std;

void swapAlternate(int altArr[],int size)
{
    int temp =0;
    
    for(int i=0;i<size; i += 2)
    {
        if(i+1<size)
        {
            // temp = altArr[i];
            // altArr[i] = altArr[j];
            // altArr[j] = temp;

            swap(altArr[i],altArr[i+1]); //inbuilt
        }
    }
   
   for(int i=0;i<size;i++)
    cout<<altArr[i]<<"\t";
}

int main(void)
{
    int arr[5] ={10,20,30,40,50};

    swapAlternate(arr,5);
    
    cout <<"\n";
    int brr[4] ={10,20,30,40};

    swapAlternate(brr,4);
  
    exit(0);
}