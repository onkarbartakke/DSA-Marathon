#include <bits/stdc++.h>

using namespace std;

/*
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, 
and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k 
coins optimally.
*/
class Solution
{
public:
    int solve(int ind, int k, vector<vector<int>> &piles, vector<vector<int>> &dp)
    {
        if (ind == piles.size() || k <= 0)
            return 0;

        if (dp[ind][k] != -1)
            return dp[ind][k];

        int best = solve(ind + 1, k, piles, dp);

        int sum = 0;

        for (int i = 0; i < min((int)piles[ind].size(), k); i++)
        {
            sum += piles[ind][i];

            best = max(best, sum + solve(ind + 1, k - i - 1, piles, dp));
        }

        return dp[ind][k] = best;
    }

    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {

        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return solve(0, k, piles, dp);
    }
};