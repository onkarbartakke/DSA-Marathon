#include <bits/stdc++.h>

using namespace std;
/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Recall that a subsequence of an array nums is a list 
nums[i1], nums[i2], ..., nums[ik] with 0 <= i1 < i2 < ... < ik <= nums.length - 1, and that a sequence seq is 
arithmetic if seq[i+1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/
int lengthOfLongestAP(int nums[], int n)
{
    // code here

    if (n <= 2)
        return n;

    vector<unordered_map<int, int>> dp(n);
    //vector<vector<int>>dp(n, vector<int>(2000,0));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            // cout<<"\nDiff is : "<<diff<<"\n";
            dp[i][diff] = dp[j].count(diff) > 0 ? 1 + dp[j][diff] : 2;

            res = max(res, dp[i][diff]);
        }
    }

    return res;
}

/*
This problem is similar to Longest Increasing Subsequence problem. The difference is that we need to consider the arithmetic
difference in this problem. How to keep track of the length as well as the difference? We can use a hashmap, whose key is the
difference and value is the length. Then we can solve the problem with dynamic programming:
As noted in the problem description, 2 <= A.length, so we don't need to consider the edge case when there is no element or only
one element in A. The base case is A.length == 2, then A itself is the longest arithmetic subsequence because any two numbers 
meet the condition of arithmetic.
The optimization step is that for two elements A[i] and A[j] where j < i, the difference between A[i] and A[j] (name it diff) 
is a critical condition. If the hashmap at position j has the key diff, it means that there is an arithmetic subsequence ending 
at index j, with arithmetic difference diff and length dp[j][diff]. 
And we just add the length by 1. If hashmap does not have the key diff, then those two elements can form a 2-length arithmetic 
subsequence. And update the result if necessary during the iteration.
*/