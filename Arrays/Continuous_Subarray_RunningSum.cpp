#include <bits/stdc++.h>

using namespace std;
/*
Given an integer array nums and an integer k, return true if nums has a continuous subarray of 
size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int runningSum = 0;

        unordered_map<int, int> mp;

        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            runningSum += nums[i];

            if (k != 0)
                runningSum %= k;

            if (mp.find(runningSum) != mp.end())
            {
                if (i - mp[runningSum] > 1)
                    return true;
            }
            else
                mp[runningSum] = i;
        }

        return false;
    }
};