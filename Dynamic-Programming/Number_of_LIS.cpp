#include <bits/stdc++.h>

using namespace std;


// The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing Subsequence and 
// the coresponding number of these sequence which ends with nums[i], respectively. That is:

// len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
// cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].

// Then, the result is the sum of each cnt[i] while its corresponding len[i] is the maximum length.


class Solution
{
    public:
    int findNumberOfLIS(vector<int> &nums)
    {

        int n, i, j;
        n = nums.size();

        vector<pair<int, int>> dp(n, {1, 1});

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i].first == dp[j].first + 1)
                    {
                        dp[i].second += dp[j].second;
                    }

                    if (dp[i].first < dp[j].first + 1)
                    {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    }
                }
            }
        }

        int max_len = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i].first == max_len)
            {
                res += dp[i].second;
            }
            else if (dp[i].first > max_len)
            {
                max_len = dp[i].first;
                res = dp[i].second;
            }
        }

        return res;
    }
};

int main()
{
}