#include <bits/stdc++.h>
/*
Given an array nums of positive integers. Your task is to select some subset of nums, 

multiply each element by an integer and add all these numbers.
 The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.

Return True if the array is good otherwise return False
 */

int GCD(int a, int b)
{

    if (b == 0)
        return a;

    if (b == 1)
        return 1;

    return GCD(b, a % b);
}

bool isGoodArray(vector<int>&nums)
{

    int i, prev;
    prev = nums[0];

    for (i = 1; i < nums.size(); i++)
    {
        prev = GCD(prev, nums[i]);

        if (prev == 1)
            return true;
    }

    return prev == 1;
}

int main()
{
    vector<int>nums(10);

    isGoodArray(nums);
}