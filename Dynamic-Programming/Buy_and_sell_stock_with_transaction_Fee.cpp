#include <bits/stdc++.h>

using namespace std;
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer 
fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need 
to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {

        int mini = prices[0];

        int ans = 0;
        for (auto p : prices)
        {
            if (p < mini)
                mini = p;
            else if (p > mini + fee)
            {
                ans += (p - mini - fee);
                mini = p - fee;
            }
        }

        return ans;
    }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/201603/Python.-Greedy-is-good.