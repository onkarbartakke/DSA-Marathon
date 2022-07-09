#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {

        int total = accumulate(stones.begin(), stones.end(), 0);

        int sum = total / 2;
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int s = 1; s <= sum; s++)
            {
                if (stones[i - 1] > s)
                    dp[i][s] = dp[i - 1][s];
                else
                    dp[i][s] = max(dp[i - 1][s], dp[i - 1][s - stones[i - 1]] + stones[i - 1]);
            }
        }

        return (total - 2 * (dp[n][sum]));
    }
};

// https://leetcode.com/problems/last-stone-weight-ii/submissions/
/*
int lastStoneWeightII(vector& stones) {
//let say array be [a,b,c,d]
//answer = (a+b)-(c+d) OR
//answer = a-(b+c+d) Or
//answer = (d+b)-(a+c) and so on.. any combination could be possible
//notice that in general I can say that
//answer = S1-S2
//where S1 is sum of some of the numbers and S2 is sum of rest of numbers
//also note that S1+S2 = SUM (sum of all numbers)
//S1 >= S2 beacuse negative answer is not possible
//now we have to minimise answer
//answer = SUM - 2*S2 (Just substituting S1 by SUM-S2)
//To minimise answer S2 has to be maximum
//Now, max value of S2 is SUM/2 (bigger than this and answer would be negative which is not possible)
//so the question reduces to find closest sum (sum of numbers) to (SUM/2)
//now this could be understood as subset sum problem or 0/1 knapsack problem

    int sum = 0;
    int total = 0;
    int n = stones.size();
    for(int i = 0;i<n;i++) {
        total+=stones[i];
    }
    sum = total/2;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i =1;i<=n;i++) {
        for(int j = 1;j<=sum;j++) {
            if(stones[i-1]>j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-stones[i-1]]+stones[i-1]);
            }
        }
    }
    return total-(2*dp[n][sum]);
}*/