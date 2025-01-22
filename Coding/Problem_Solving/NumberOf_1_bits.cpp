/*
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

*/

#include<iostream>

using namespace std;

int hammingWeight(uint32_t n);

int main(void)
{
    uint32_t no = 0;
    cout<<"enter no : ";
    cin>>no;

    cout<<hammingWeight(no)<<endl;
    exit(0);
}


int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0)
        {
            if(n&1) //checked last bit is on or not
                count++;
            
            n=n>>1;
        }
        
        return count;
}