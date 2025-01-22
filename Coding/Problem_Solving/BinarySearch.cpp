#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size,int key)
{
    int start = 0;
    int end = size;
    int mid;

    while(start <= end)
    {
        mid = (start+end)/2;

        if(arr[mid] == key)
            return mid;
        
        else if(key > arr[mid]) 
            start = mid + 1;
        else
            end = mid - 1; 
    }
    return -1;
}

int main(void)
{
    int evenArr [] = {10,12,18,25,30,33};
    //int oddArr [] = {50,45,40,38,30};

    int index = BinarySearch(evenArr,6,30);

    cout<<"Index of 30 in evenArr[] is :: "<<index<<endl;

    exit(0);
}