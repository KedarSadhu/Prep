/*
Problem Statement-1: Check if a string is a Palindrome (i.e. Reversing a string matches with original source string).a.       Implement function ‘palindromeChecker’ that accepts input as an array of strings and identifies which strings are Palindrome.b.       String comparison should be case insensitive. Ignore space characters between words of string. i.e. “Race car” is Palindrome, since “racecar” matches with original and reverse string.Example input:
[“The quick brown fox jumped over the sleeping dog”,”Oozy rat in a sanitary zoo”,”Carla loves chocolate”]
*/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool palindrom(string s1)
{
	cout << "lower string :: " << s1;
	bool flag = false;

	for (int i = 0 ,j = s1.length(); i <= j; i++,j--)
	{
		if (s1[i] == s1[j])
		{
			flag = true;
			continue;
		}
		else
		{
			if (s1[i] == ' ' || s1[j] == ' ')
				continue;

			else
			{
				flag = false;
				break;
			}

		}
	}
	return flag;

}
int main()
{
	bool res = palindrom("oozy rat in a sanitary zoo");

	if (res)
		cout << "Given string is palindrom" << endl;
	else
		cout << "\nGiven string is not palindrom" << endl;

	return 0;
}