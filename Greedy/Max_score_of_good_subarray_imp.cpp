#include <bits/stdc++.h>

using namespace std;
/*
You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). 
A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

 */
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {

        int left, right, mn;

        int res = 0;

        left = k;
        right = k;
        mn = nums[k];
        res = mn;

        int n = nums.size();
        while (left > 0 || right < n - 1)
        {
            if (left > 0 && right < n - 1)
            {
                if (nums[left - 1] > nums[right + 1])
                {
                    mn = min(mn, nums[left - 1]);
                    left--;
                    res = max(res, mn * (right - left + 1));
                }
                else
                {
                    mn = min(mn, nums[right + 1]);
                    right++;
                    res = max(res, mn * (right - left + 1));
                }
            }
            else if (left > 0)
            {
                mn = min(mn, nums[left - 1]);
                left--;
                res = max(res, mn * (right - left + 1));
            }
            else if (right < n - 1)
            {
                mn = min(mn, nums[right + 1]);
                right++;
                res = max(res, mn * (right - left + 1));
            }
        }

        return res;
    }
};