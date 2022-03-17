#include <bits/stdc++.h>

using namespace std;
/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, 
it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer 
to the first example for a better explanation.

Return the minimum total cost of the cuts.

 
 */
class Solution
{
public:
    int DFS(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
    {
        if (j - i <= 1)
        {
            dp[i][j] = 0;
            return 0;
        }

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        for (int k = i + 1; k < j; k++)
        {
            dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + DFS(cuts, i, k, dp) + DFS(cuts, k, j, dp));
        }

        return dp[i][j];
    }
    int minCost(int n, vector<int> &cuts)
    {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), INT_MAX));

        return DFS(cuts, 0, cuts.size() - 1, dp);
    }
};

// Algo : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/780880/DP-with-picture-(Burst-Balloons)