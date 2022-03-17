#include <bits/stdc++.h>

using namespace std;


/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 


*/
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {

        unordered_map<int, int> abSum;

        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                abSum[a + b]++;
            }
        }

        int count = 0;

        for (auto c : nums3)
        {
            for (auto d : nums4)
            {
                auto it = abSum.find(0 - c - d);

                if (it != abSum.end())
                    count += (it->second);
            }
        }

        return count;
    }
};