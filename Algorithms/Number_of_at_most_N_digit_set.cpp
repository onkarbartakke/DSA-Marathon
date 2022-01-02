#include <bits/stdc++.h>

using namespace std;

/*
Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. 
For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

 

Example 1:

Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
*/
class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {

        string nS = to_string(n);
        int ndigits = nS.size();
        int d = digits.size();

        int ans = 0;
        for (int i = 1; i < ndigits; i++)
        {
            ans += pow(d, i);
        }

        for (int i = 0; i < ndigits; i++)
        {
            bool sameNum = false;

            for (auto s : digits)
            {
                if (s[0] < nS[i])
                    ans += pow(d, ndigits - i - 1);
                else if (s[0] == nS[i])
                {
                    sameNum = true;
                    break;
                }
            }

            if (!sameNum)
                return ans;
        }

        return ans + 1;
    }
};