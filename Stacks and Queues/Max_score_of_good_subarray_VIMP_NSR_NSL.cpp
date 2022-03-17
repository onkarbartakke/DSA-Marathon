#include <bits/stdc++.h>

using namespace std;
/*
You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). 
A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.
*/

// A greedy simple solution for this exits in greedy folder
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        nums.push_back(0);
        stack<int> st;
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                int height = nums[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                if (k < i && k > left)
                    res = max(height * (i - left - 1), res);
            }
            st.push(i);
        }
        return res;
    }
};