#include<iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    int unique  = 0;
    for( int i = 0 ;i<size ;i++)
    {
        unique =unique ^ arr[i];
    }

    return unique;
}


int main(void)
{
    int arr [5] = {4,2,1,3,1};
    int ans = findUnique(arr,5); 
    cout << "unique no in arr :: " <<ans<<endl;

    int brr[11] = {5,3,1,5,1,3,4,7,4,8,8};
    ans = findUnique(brr,1); 
    cout << "unique no in brr :: " <<ans<<endl;

    exit(0);
}