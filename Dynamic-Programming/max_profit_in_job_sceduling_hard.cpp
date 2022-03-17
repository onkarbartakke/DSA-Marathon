#include <bits/stdc++.h>

using namespace std;
/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in
 the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
*/
class Solution
{
public:
    int solve(vector<vector<int>> &jobs, vector<int> &dp, int pos)
    {
        if (pos >= jobs.size())
            return 0;

        if (dp[pos] != -1)
            return dp[pos];

        vector<int> temp = {jobs[pos][1], INT_MIN, INT_MIN};

        int i = lower_bound(jobs.begin(), jobs.end(), temp) - jobs.begin();

        return dp[pos] = max(solve(jobs, dp, pos + 1), jobs[pos][2] + solve(jobs, dp, i));
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {

        int i, n;
        n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for (i = 0; i < n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1, -1);

        return solve(jobs, dp, 0);
    }
};