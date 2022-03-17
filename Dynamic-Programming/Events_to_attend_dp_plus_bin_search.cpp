#include <bits/stdc++.h>

using namespace std;
/*
You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi,
 and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number
  of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day
 is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.
*/
class Solution
{
    public:
    int solve(vector<vector<int>> &events, int pos, int k, vector<vector<int>> &dp)
    {
        if (k == 0 || pos >= events.size())
            return 0;

        if (dp[pos][k] != -1)
            return dp[pos][k];

        vector<int> temp = {events[pos][1], INT_MAX, INT_MAX};
        int i = upper_bound(events.begin(), events.end(), temp) - events.begin();

        return dp[pos][k] = max(solve(events, pos + 1, k, dp), events[pos][2] + solve(events, i, k - 1, dp));
    }
    
    int maxValue(vector<vector<int>> &events, int k)
    {

        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return solve(events, 0, k, dp);
    }
};