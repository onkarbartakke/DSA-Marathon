#include <bits/stdc++.h>

using namespace std;
/*
You are given a string s consisting of only lowercase English letters. In one operation, you can:

Delete the entire string s, or
Delete the first i letters of s if the first i letters of s are equal to the 
following i letters in s, for any i in the range 1 <= i <= s.length / 2.
For example, if s = "ababc", then in one operation, you could delete the first 
two letters of s to get "abc", since the first two letters of s and the following two 
letters of s are both equal to "ab".

Return the maximum number of operations needed to delete all of s
*/
class Solution
{
    string s;
    int dp[4100];
    vector<int> prefix_function(int st)
    {
        int n = s.length() - st;
        vector<int> pi(n);
        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && s[i + st] != s[j + st])
                j = pi[j - 1];
            if (s[i + st] == s[j + st])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int helper(int st)
    {
        int n = s.size() - st;
        if (dp[st])
            return dp[st];
        vector<int> prefix = prefix_function(st);
        int ans = 1;
        for (int j = 1; j < n; j += 2)
        {
            // Eg if j = 1, prefix[1] should be 1, such that string becomes "xx....", prefix[1] = 1, means that that the longest prefix which is equal to suffix at i=1 is 1, so the first character is equal to the next character.
            // Similarly at j = 3, we need prefix[3] value to be 2, so that the first two characters are equal to the next two characters, The string could be of the form "abab...." .
            int val = (j + 1) / 2;
            if (prefix[j] == val)
            {
                ans = max(ans, 1 + helper(st + prefix[j]));
            }
        }
        return dp[st] = ans;
    }

    public:
    int deleteString(string S)
    {
        s = S;
        return helper(0);
    }
};