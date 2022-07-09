#include <bits/stdc++.h>

using namespace std;
/*
You are given an integer array nums and an integer x. In one operation, you can either remove 
the leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 */
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        unordered_map<int, int> mp;

        int targetSum = -x;

        for (auto it : nums)
            targetSum += it;

        if (targetSum == 0)
            return nums.size();

        mp.insert({0, -1});

        int sum = 0;

        int maxLen = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (mp.find(sum - targetSum) != mp.end())
            {
                maxLen = max(maxLen, i - mp[sum - targetSum]);
            }

            mp[sum] = i;
        }

        if (maxLen == INT_MIN)
            return -1;
        else
            return nums.size() - maxLen;
    }
};

//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/935935/Java-Detailed-Explanation-O(N)-Prefix-SumMap-Longest-Target-Sub-Array