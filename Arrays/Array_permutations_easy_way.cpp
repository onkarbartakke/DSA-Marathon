#include <bits/stdc++.h>

using namespace std;
/*
Given an array nums of distinct integers, 
return all the possible permutations. You can return the answer in any order.
*/
class Solution
{
public:
    void PermuteRecursive(vector<int> &nums, int begin, vector<vector<int>> &ans)
    {
        if (begin >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        int n = nums.size();
        for (int i = begin; i < n; i++)
        {
            swap(nums[begin], nums[i]);
            PermuteRecursive(nums, begin + 1, ans);
            swap(nums[begin], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;

        PermuteRecursive(nums, 0, ans);

        return ans;
    }
};