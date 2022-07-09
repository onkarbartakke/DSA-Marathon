#include <bits/stdc++.h>

using namespace std;
/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/
class Solution
{
public:
    int atMost(vector<int> &a, int k)
    {
        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        int n = a.size();

        int res = 0;
        for (j = 0; j < n; j++)
        {
            if (mp[a[j]] == 0)
            {
                k--;
            }

            mp[a[j]]++;

            while (k < 0)
            {
                mp[a[i]]--;

                if (mp[a[i]] == 0)
                    k++;

                i++;
            }

            res += (j - i + 1);
        }

        return res;
    }

    
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

/*
Intuition:
First you may have feeling of using sliding window.
Then this idea get stuck in the middle.

This problem will be a very typical sliding window,
if it asks the number of subarrays with at most K distinct elements.

Just need one more step to reach the folloing equation:
exactly(K) = atMost(K) - atMost(K-1)


Explanation
Write/copy a helper function of sliding window,
to get the number of subarrays with at most K distinct elements.
Done.

https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window
*/