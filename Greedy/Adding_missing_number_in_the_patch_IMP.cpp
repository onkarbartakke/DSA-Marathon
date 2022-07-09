#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {

        long misses = 1, added = 0;

        int i = 0;

        while (misses <= n)
        {
            if (i < nums.size() && nums[i] <= misses)
            {
                misses += nums[i];
                i++;
            }
            else
            {
                misses += misses;
                added++;
            }
        }

        return added;
    }
};

//https://leetcode.com/problems/patching-array/discuss/78492/C%2B%2B-8ms-greedy-solution-with-explanation

//https://leetcode.com/problems/patching-array/discuss/78488/Solution-%2B-explanation