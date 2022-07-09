#include <bits/stdc++.h>

using namespace std;

/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the 
partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


-*/
bool isPalindrome(string s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;

        l++;
        r--;
    }

    return true;
}

int solve(string s, int l, int r, vector<vector<int>> &dp)
{
    if (l >= r)
        return 0;

    if (isPalindrome(s, l, r))
    {
        dp[l][r] = 0;
        return 0;
    }

    if (dp[l][r] != -1)
        return dp[l][r];

    int res = INT_MAX;

    for (int i = l; i < r; i++)
    {
        res = min(res, 1 + solve(s, l, i, dp) + solve(s, i + 1, r, dp));
    }

    return dp[l][r] = res;
}


int palindromicPartition(string str)
{
    // code here

    int n = str.length();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    if (isPalindrome(str, 0, n - 1))
        return 0;

    return solve(str, 0, n - 1, dp);
}