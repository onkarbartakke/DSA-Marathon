#include <bits/stdc++.h>

using namespace std;
/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original 
string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. 
(i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

 */


//Tabulation approach, this can be optimized further in 1D DP

class Solution
{
public:
    int numDistinct(string s, string t)
    {

        int n = s.length();  
        int m = t.length();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return (int)dp[n][m];
    }
};

// Recursive approach which can be easily memoized
int solve(int i, int j, string &s, string &t)
{
    if(j<0) // We have found complete str t in main str s
    {
        return 1;
    }

    if(i<0) // we have exhausted the main string
    {
        return 0;
    }

    if(s[i] == t[j]) // Here we have 2 options either er include last char in str t[j] or we just move on and find some other char in t, which is same as t[j]
    {
        return solve(i-1,j-1,s,t) + solve(i-1,j,s,t);
    }
    else
    {
        return solve(i-1,j,s,t); 
    }
}
int main()
{
    string s,t;

    cin>>s>>t;

    int n = s.length();
    int m = t.length();

    return solve(n-1,m-1,s,t);
}