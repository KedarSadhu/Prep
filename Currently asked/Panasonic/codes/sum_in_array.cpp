/*

Given an array of integers arr and an integer k, create a boolean function that checks 
if there exist two elements in arr such that we get k when we add them together. 

Example 1: Input: arr = [4, 5, 1, -3, 6], k = 11 
Output: true Explanation: 5 + 6 is equal to 11 

Example 2: Input: arr = [4, 5, 1, -3, 6], k = -2 
Output: true Explanation: 1 + (-3) is equal to -2 

Example 3: Input: arr = [4, 5, 1, -3, 6], k = 8 
Output: false Explanation: there is no pair that sums up to 8 

*/

#include<iostream>

using namespace std;

bool checksum(int *ptr,int k,int len)
{
    bool res = false;

    for (int left = 0; left < len;left++)
    {
        for (int right = left + 1; right <= len;right++)
        {
            if(ptr[left]+ptr[right] == k)
            {
                res = true;
            }
        }
    }

   return res;
}

int main()
{
    int arr[] = {4, 5, 1, -3, 6 };
    cout<<checksum(arr,-2,5)<<endl;
    return 0;
}