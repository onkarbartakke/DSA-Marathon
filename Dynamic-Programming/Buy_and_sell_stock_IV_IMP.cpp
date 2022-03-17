#include <bits/stdc++.h>

using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again)
*/
class Solution
{
    public:
    int maxProfit(int k, vector<int> &prices)
    {

        if (k == 0)
            return 0;

        int n = prices.size();

        int profit = 0;
        if (2 * k >= n)
        {
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                    profit += (prices[i] - prices[i - 1]);
            }

            return profit;
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int i = 1; i <= k; i++)
        {
            int prevProfit = dp[i - 1][0] - prices[0];

            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + prevProfit);
                prevProfit = max(prevProfit, dp[i - 1][j] - prices[j]);
            }
        }

        return dp[k][n - 1];
    }
};


/**
 * dp[i, j] represents the max profit up until prices[j] using at most i transactions. 
 * dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
 *          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
 * dp[0, j] = 0; 0 transactions makes 0 profit
 * dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
 */
