// Input:
// 1,0,1,0,1,1,1,0,0,1
 
// Find out how many times 1 occurs in this array without using any comparison operator
// (=, <, >, <=, >=)
 
// Output:
// 6

#include<iostream>
using namespace std;

int main(void)
{
    int arr[] = {1, 0, 1, 0, 1, 1, 1, 0, 0, 1};
    int count = 0;

    for(int i =0;i<10;i++)
    {
        if(arr[i]&1)
            count++;
    }

    cout<<count;
    return 0;
}
 
// What is difference between process and thread in terms of memory sharing?
 
// What is socket? How would you create a socket in Linux?
 
// What is segmentation fault? What would be possible causes of segmentation faults happening?
 
// If a line is represented as a string of variable length using a pointer, a page has multiple lines, 
// and a book has multiple pages, how would you define a book in terms of lines?
 