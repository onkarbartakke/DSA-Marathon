#include <bits/stdc++.h>

using namespace std;
/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the 
elements in the subarray is strictly less than k.

 
 */
class Solution
{
    public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {

        int n, start, end, prod = 1;
        n = nums.size();

        start = 0;
        end = 0;
        int count = 0;
        while (end < n)
        {
            prod *= nums[end];

            while (prod >= k && start <= end)
            {
                prod /= nums[start];
                start++;
            }

            if (prod < k)
                count += (end - start) + 1;

            end++;
        }

        return count;
    }
};