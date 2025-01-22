#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<numeric>

using namespace std;

int climbStairs(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  return climbStairs(n - 1) + climbStairs(n - 2);
}

int MaxConsecutiveOnes(int *arr,int size)
{
  // [0,1,1,0,0,1,1,1,0]
  // output = 3
  int l = 0;
  int r = 0;
  int max1 = 0;
  int count = 0;
  while (l < size)
  {
    if (arr[l] == 1)
    {
      r = l;
      while (arr[r] == 1 && r < size)
      {
        r++;
        max1++;
      }
    }
    count = max(max1, count);
    max1 = 0;
    l++;
  }

  return count;
}

void charCount(const char * ptr)
{
  map<char, int>mCharmap;
  map<char, int>::iterator it;
  while (*ptr != '\0')
  {
    if ((it = mCharmap.find(*ptr)) != mCharmap.end())
    {
      ++(it->second);
    }
    else
    {
      mCharmap.insert(make_pair(*ptr, 1));
    }
    ptr++;
  }

  //Display count
  for (it = mCharmap.begin(); it != mCharmap.end(); ++it)
  {
    cout << it->first << "\t";
    cout << it->second << endl;
  }
}

void moveZero(int * ptr, int size)
{
  //for (int l = 0; l < size; l++)
  //{
  //  //--for (int r = l + 1; r < size-1; r++)
  //  for (int r = l ; r < size-1; r++)
  //  {
  //    if (ptr[r] == 0)
  //    {
  //      int temp = ptr[r];
  //      ptr[r] = ptr[r + 1];
  //      ptr[r + 1] = temp;
  //    }
  //  }
  //}

  int l = 0;
  int temp = 0;
  for (int r = 0; r < size; r++)
  {
    if (ptr[r] != 0)
    {
      int temp = ptr[r];
      ptr[r] = ptr[l];
      ptr[l] = temp;

      l++;
    }
  }
  for (int l = 0; l < size; l++)
    cout << ptr[l] << endl;
}

int returnMissingNumber(vector<int>& nums)
{
  //vector<int>vec(nums.size()+1);
  //iota(vec.begin(), vec.end(), 0);
  //bool isPresent = false;

  //for (int i = 0; i < vec.size(); i++) // complete array
  //{
  //  for (int j = 0; j < nums.size(); j++) //input array
  //  {
  //    if (vec[i] == nums[j])
  //    {
  //      isPresent = true;
  //      break;
  //    }
  //    else
  //    {
  //      isPresent = false;
  //    }
  //  }

  //  if (!isPresent)
  //    return i;
  //}
  //return -1;

  //simple approch to find missing number
  int n = nums.size();
  int expectedSum = n * (n + 1) / 2; // 6*7 / 2 = 42/2 => 21
  int actualSum = 0;
  for (int index = 0; index < nums.size(); index++)
  {
    actualSum += nums[index];
  }

  return expectedSum - actualSum;
}

void LongestPallindromicSubstring(string &str)
{
  int left = 0;
  int right = 1;
  bool isPalindrom = true;

  while (left < str.length())
  {
    while (right < str.length() && str[left] != str[right])
      right++;

    if (str[left] == str[right])
      break;

    left++;
    right = left + 1;
  }

  int tempL = left;
  int tempR = right+1;
  while (left < right)
  {
    if (str[left] != str[right])
    {
      isPalindrom = false;
      break;
    }
    else
    {
      left++;
      right--;
    }
  }

  if (isPalindrom)
  {
    for (int i = tempL; i < tempR; i++)
      cout << str[i];
  }
  cout << endl;

  
}

void mulMat(vector<vector<int>>& m1, vector<vector<int>>& m2) 
{
  int M1Row = m1.size();
  int M1Col = m1[0].size();
  int M2Row = m2.size();
  int M2Col = m2[0].size();
  vector<vector<int>> res;

  if (M1Col != M2Row) 
  {
    cout << "Invalid Input" << endl;
    exit(EXIT_FAILURE);
  }

  // Resize result matrix to fit the result dimensions
  res.resize(M1Row, vector<int>(M2Col, 0));

  for (int i = 0; i < M1Row; i++) 
  {
    for (int j = 0; j < M2Col; j++) 
    {
      for (int k = 0; k < M1Col; k++) 
      {
        res[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }

  cout << "Multiplication of given two matrices is:\n";
  for (const auto& row : res) 
  {
    for (int val : row) 
    {
      cout << val << "\t";
    }
    cout << endl;
  }
}

int main()
{
  //cout << "Output : " << climbStairs(4) << endl;

  //int arr[] = { 0, 1, 1, 0, 0, 1, 1, 1, 0 , 1 , 1 , 1 , 1 , 1 , 1 ,1 };
  //cout << "Output : " << MaxConsecutiveOnes(arr,(sizeof(arr)/4)) << endl;


 //charCount("aabbabccccaccbcccaaa");

  //int arr[] = { 1,0,2,3,0,2 };
  //int arr[] = { 0,1,0,2,0,3,0,2 };
  //moveZero(arr, (sizeof(arr) / 4));

  //vector<int>temp = { 3,0,1 };
  //cout << "Output : " << returnMissingNumber(temp) << endl;
  
  /*string s = "cbbd";
  LongestPallindromicSubstring(s);*/

  vector<vector<int>> m1 = { {1, 2, 3}, {4, 5, 6} };
  vector<vector<int>> m2 = { {7}, {8}, {9} };

  mulMat(m1, m2);

  return 0;
}

