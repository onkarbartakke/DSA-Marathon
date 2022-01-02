#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    void nextPermutation(vector<int> &nums)
    {

        int i, j;

        if (nums.size() == 1)
            return;

        for (i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                break;
            }
        }

        if (i < 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        else
        {
            j = nums.size() - 1;

            for (; j > i; j--)
            {
                if (nums[j] > nums[i])
                    break;
            }

            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;

            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};