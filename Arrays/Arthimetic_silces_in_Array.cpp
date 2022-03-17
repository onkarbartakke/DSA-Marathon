#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        int n = nums.size();

        if (n < 3)
            return 0;

        int curr_len = 0, curr_diff = nums[1] - nums[0], last_diff;
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            last_diff = nums[i + 1] - nums[i];

            if (last_diff == curr_diff)
                curr_len++;
            else
            {
                curr_len = 0;
                curr_diff = last_diff;
            }

            ans += curr_len;
        }

        return ans;
    }
};

/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two 
consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.
*/