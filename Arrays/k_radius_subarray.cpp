#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    vector<int> getAverages(vector<int> &nums, int k)
    {

        long long int n = nums.size();
        vector<int> ans(n, -1);

        long long int sum = 0;
        long int len = 2 * k + 1;

        if (n < len)
            return ans;

        for (long long int i = 0; i < len; i++)
            sum += nums[i];

        long long int i = k;
        for (i = k; i + k + 1 < n; i++)
        {
            ans[i] = (sum / (2 * k + 1));

            sum = sum - nums[i - k];
            sum = sum + nums[i + k + 1];
        }

        ans[i] = (sum / (2 * k + 1));
        return ans;
    }
};