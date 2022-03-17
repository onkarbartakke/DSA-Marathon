#include <bits/stdc++.h>

using namespace std;
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
class Solution
{
    public:
    int maxProfit(vector<int> &prices)
    {

        int n, i, j;
        n = prices.size();

        vector<vector<int>> dp(3, vector<int>(n, 0));

        // 0th Row for No-stock state
        // 1st Row for In-Hand State
        // 2nd Row for Sold State;

        dp[0][0] = 0;
        dp[1][0] = -1 * prices[0];
        dp[2][0] = 0;

        for (int i = 1; i < n; i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[2][i - 1]);

            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);

            dp[2][i] = dp[1][i - 1] + prices[i];
        }

        return max(dp[0][n - 1], dp[2][n - 1]);
    }
};