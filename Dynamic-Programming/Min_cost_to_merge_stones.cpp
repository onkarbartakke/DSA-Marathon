#include <bits/stdc++.h>

using namespace std;
/*
There are n piles of stones arranged in a row. The ith pile has stones[i] stones.

A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.

Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.

 
 */


class Solution
{
    public:
    int dp[50][50][50];
    int minCost(int i, int j, int piles, vector<int> &prefixsum, int &K)
    {

        // Cost of converting segment [i..i] into 1 pile is zero
        if (i == j && piles == 1)
            return 0;

        // Cost of converting segment[i..i] into other than 1 pile is not possible , so placed MAX value
        if (i == j)
            return INT_MAX / 4;

        // Check whether the subproblem has already been solved .
        if (dp[i][j][piles] != -1)
            return dp[i][j][piles];

        // If segment[i...j] is to converted into 1 pile
        if (piles == 1)
        {
            // Here dp(i,j,1) = dp(i,j,K) + sum[i...j]

            return dp[i][j][piles] = minCost(i, j, K, prefixsum, K) + (i == 0 ? prefixsum[j] : prefixsum[j] - prefixsum[i - 1]);
        }
        else
        {

            // dp(i,j,piles) = min( dp(i,j,piles), dp(i,t,1) + dp(t+1,j,piles-1)) for all t E i<=t<j
            int cost = INT_MAX / 4;
            for (int t = i; t < j; t++)
            {
                cost = min(cost, minCost(i, t, 1, prefixsum, K) + minCost(t + 1, j, piles - 1, prefixsum, K));
            }
            return dp[i][j][piles] = cost;
        }
    }

    int mergeStones(vector<int> &stones, int k)
    {

        // the size of the stones
        int n = stones.size();

        /* 
        Check whether we will be able to merge n piles into 1 pile . 
            
            In step-1 we merge k pile and then we are left with n-k+1 piles or n-(k-1);
            In Step-2 we again merge k pile and then we are left with ((n-k+1)-k)+1 or n-2*(k-1);
            In Step-3 we gain merge k pile and left with (((n-k+1)-k+1)-k)+1 or n-3*(k-1)
            .......
            .......
            .......
            After some m steps we should be left with 1 pile 
            Therefore , n-m*(k-1) == 1
                   (n-1)-m*(k-1)=0;
                   Since m needs to be an integer therefore , 
                   if (n-1)%(k-1) == 0 , 
                   then we can merge otherwise not possible.
        */

        if ((n - 1) % (k - 1) != 0)
            return -1;
        int sum = 0;
        vector<int> prefixsum;

        // Calculating the prefix sum so that sum of any segment[i..j] can be calculated easily
        for (int i = 0; i < stones.size(); i++)
        {
            sum += stones[i];
            prefixsum.push_back(sum);
        }

        memset(dp, -1, sizeof(dp));

        // find the minimum cost to merge stones[0...n-1] into 1 pile
        return minCost(0, n - 1, 1, prefixsum, k);
    }
};

// Explanation :
// https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/1432667/Explained-to-make-you-Visualise-the-solution-.-Detailed-Explanation