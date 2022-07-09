#include <bits/stdc++.h>

using namespace std;
/*
You are given an integer array nums of 2 * n integers. 
You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. 
To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.
*/
class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        int N = n / 2;

        vector<vector<int>> left(N + 1), right(N + 1);

        for (int mask = 0; mask < (1 << N); mask++)
        {
            int sz = 0, l = 0, r = 0;

            for (int i = 0; i < N; i++)
            {
                if (mask & (1 << i))
                {
                    sz++;
                    l += nums[i];
                    r += nums[i + N];
                }
            }

            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for (int sz = 0; sz <= N; sz++)
        {
            sort(right[sz].begin(), right[sz].end());
        }

        int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        for (int sz = 1; sz <= N; sz++)
        {
            for (auto a : left[sz])
            {
                int b = (sum - 2 * a) / 2;

                int rsz = N - sz;
                auto itr = lower_bound(right[rsz].begin(), right[rsz].end(), b);

                if (itr != right[rsz].end())
                {
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                }

                if (itr != right[rsz].begin())
                {
                    auto it = itr;
                    --it;
                    res = min(res, abs(sum - 2 * (a + (*it))));
                }
            }
        }

        return res;
    }
};