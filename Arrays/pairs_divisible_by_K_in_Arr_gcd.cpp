#include <bits/stdc++.h>

using namespace std;
/*
Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums[i] * nums[j] is divisible by k.
*/
class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;

        long long res = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int gcd1 = __gcd(nums[i], k);
            int gcd2 = (k / gcd1);

            if (gcd2 == 1)
            {
                res += i;
            }
            else
            {
                for (auto it : mp)
                {
                    if (it.first % gcd2 == 0)
                        res += it.second;
                }
            }

            mp[gcd1]++;
        }

        return res;
    }
};
