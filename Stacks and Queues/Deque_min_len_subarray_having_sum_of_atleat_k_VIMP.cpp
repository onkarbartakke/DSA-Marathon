#include <bits/stdc++.h>

using namespace std;
/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
If there is no such subarray, return -1.

A subarray is a contiguous part of an array.
*/
class Solution
{
    public:
    int shortestSubarray(vector<int> &a, int k)
    {

        deque<long int> dq;

        long int res = INT_MAX;
        long int n = a.size();
        vector<long int> nums(n);

        for (long int i = 0; i < n; i++)
            nums[i] = a[i];

        for (long int i = 0; i < n; i++)
        {
            if (i > 0)
                nums[i] += nums[i - 1];

            if (nums[i] >= k)
                res = min(res, i + 1);

            while (!dq.empty() && nums[i] - nums[dq.front()] >= k)
            {
                res = min(res, i - dq.front());
                //res = min(res, i - d.front())
                dq.pop_front();
            }

            while (!dq.empty() && nums[i] < nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return res == INT_MAX ? -1 : res;
    }
};