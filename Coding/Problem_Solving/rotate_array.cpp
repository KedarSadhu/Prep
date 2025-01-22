/*
input -- k = 2
 0   1   2   3   4   
[1   2   3   4   5]

output 

 0   1   2   3   4   
[4   5   1   2   3]
*/


#include<iostream>
#include<vector>

using namespace std;

vector<int> myrotate(vector<int>& ipArr, int k)
{
    size_t n = ipArr.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = ipArr[i];
    }
    return temp;
}

int main(void)
{
    vector<int> arr{ 1,2,3,4,5 };
    int k = 0;
    cout << "Enter number :: ";
    cin >> k;

    vector<int> brr = myrotate(arr, k);
    for (int i = 0; i < 5; i++)
    {
        cout << brr[i] << "\t";
    }
    cout << endl;
    exit(0);
}

