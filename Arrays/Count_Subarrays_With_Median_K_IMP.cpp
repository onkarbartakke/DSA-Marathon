#include <bits/stdc++.h>

using namespace std;
/*
You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.

Return the number of non-empty subarrays in nums that have a median equal to k.

Note:

The median of an array is the middle element after sorting the array in ascending order. 
If the array is of even length, the median is the left middle element.
For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
A subarray is a contiguous part of an array.
 */
class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        int idx = find(nums.begin(), nums.end(), k) - nums.begin();

        int bal = 0;

        int ans = 0;
        for (int i = idx; i < nums.size(); i++)
        {
            if (nums[i] > k)
                bal++;
            else if (nums[i] < k)
                bal--;

            mp[bal]++;

            // if(bal == 0)
            // ans++;
        }

        bal = 0;
        for (int i = idx; i >= 0; i--)
        {
            if (nums[i] > k)
                bal++;
            else if (nums[i] < k)
                bal--;

            ans += mp[-bal];
            ans += mp[-bal + 1];

            // mp[bal]++;
        }

        return ans;
    }
};