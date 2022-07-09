#include <bits/stdc++.h>

using namespace std;

/*
You are given a 0-indexed integer array nums. In one step,
remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

Return the number of steps performed until nums becomes a non-decreasing array.
*/

class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        int n = nums.size(), i, ans = 0, cnt, prev;
        stack<pair<int, int>> st;
        st.push({nums[n - 1], 0});
        for (i = n - 2; i >= 0; i--)
        {
            cnt = 0;
            while (!st.empty() && nums[i] > st.top().first)
            {
                cnt = max(cnt + 1, st.top().second);
                st.pop();
            }
            ans = max(ans, cnt);
            st.push({nums[i], cnt});
        }
        return ans;
    }
};