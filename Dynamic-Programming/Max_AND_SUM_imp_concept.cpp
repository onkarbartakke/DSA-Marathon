#include <bits/stdc++.h>

using namespace std;
/*
You are given an integer array nums of length n and an integer numSlots such that 2 * numSlots >= n. 
There are numSlots slots numbered from 1 to numSlots.

You have to place all n integers into the slots such that each slot contains at most two numbers. 
The AND sum of a given placement is the sum of the bitwise AND of every number with its respective slot number.

For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] into slot 2 is 
equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
Return the maximum possible AND sum of nums given numSlots slots.
*/
class Solution
{
public:
    int solve(int ind, vector<int> &nums, vector<int> &slotWt, int ns, map<pair<int, vector<int>>, int> &dp)
    {
        if (ind >= nums.size())
            return 0;

        if (dp.find({ind, slotWt}) != dp.end())
            return dp[{ind, slotWt}];

        int maxi = 0;
        for (int i = 1; i <= ns; i++)
        {
            if (slotWt[i] < 2)
            {
                slotWt[i]++;
                int ans = (i & nums[ind]) + solve(ind + 1, nums, slotWt, ns, dp);
                maxi = max(maxi, ans);
                slotWt[i]--;
            }
        }

        return dp[{ind, slotWt}] = maxi;
    }
    int maximumANDSum(vector<int> &nums, int numSlots)
    {

        vector<int> slotWt(numSlots + 1, 0);

        map<pair<int, vector<int>>, int> dp;
        return solve(0, nums, slotWt, numSlots, dp);
    }
};