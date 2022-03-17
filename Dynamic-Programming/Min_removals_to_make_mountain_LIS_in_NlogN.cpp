#include <bits/stdc++.h>

using namespace std;
/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

 
 */

class Solution
{
    public:
    int minimumMountainRemovals(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> left, right, LIS(n);

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(left.begin(), left.end(), nums[i]);

            if (it == left.end())
                left.push_back(nums[i]);
            else
                (*it) = nums[i];

            LIS[i] = left.size();
        }

        int curr_longest_mount = 0, res = INT_MAX;

        for (int i = n - 1; i > 0; i--)
        {
            auto it = lower_bound(right.begin(), right.end(), nums[i]);

            if (it == right.end())
                right.push_back(nums[i]);
            else
                (*it) = nums[i];

            if (LIS[i] > 1 && right.size() > 1)
            {
                curr_longest_mount = LIS[i] + right.size() - 1;

                res = min(res, n - curr_longest_mount);
            }
        }

        return res;
    }
};

/*
Intuition
We need to determine the longest increasing subsequence (LIS) starting from the left and right sides of the array, and
 find a position i (a peak) that maximizes both. We can re-use the solution from 300. Longest Increasing Subsequence.

Solution
LIS can be solved using DP, which is quadratic, or using a monotonically increasing stack. The latter is more efficient - 
linearithmic - but it's a bit tricky. As we progress through the array, we replace numbers in the stack with smaller numbers, 
while maintaining the monotonically increasing sequence.

Example: [1,3,6,2,3,5,6]

[1,3,6](add 1, 3, and 6).
[1,2,6] (3 -> 2)
[1,2,3] (6 -> 3)
[1,2,3,5,6] (add 5 and 6).
For this problem, we build our stack l from the left. We need to store the size of LIS for each point (dp[i]).

Then, we build another stack r from the right. Therefore, for each element i, we can find out the length of increasing
 (size of the left stack at i, which stored in dp[i]) and decreasing (right stack size) subsequences originating from i.
  The result is the maximum value for all potential peaks.

Note: for the mountain array to be valid, we need to only consider peaks where dp[i] > 1 and r.size() > 1.
*/