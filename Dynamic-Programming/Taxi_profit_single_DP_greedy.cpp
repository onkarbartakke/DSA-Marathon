#include <bits/stdc++.h>

using namespace std;
/*
There are n points on a road you are driving your taxi on. The n points on the road are labeled from 1 to n in the direction you are going,
and you want to drive from point 1 to point n to make money by picking up passengers. You cannot change the direction of the taxi.

The passengers are represented by a 0-indexed 2D integer array rides, where rides[i] = [starti, endi, tipi] denotes the ith passenger 
requesting a ride from point start i to point endi who is willing to give a tipi dollar tip.

For each passenger i you pick up, you earn endi - starti + tipi dollars. You may only drive at most one passenger at a time.

Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.

Note: You may drop off a passenger and pick up a different passenger at the same point.
*/
class Solution
{
    public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {

        sort(rides.begin(), rides.end());

        vector<long long> dp(n + 1, 0);

        long long int j = 0;

        for (long long int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i], dp[i - 1]);

            while (j < rides.size() && i == rides[j][0])
            {
                dp[rides[j][1]] = max(dp[rides[j][1]], dp[i] + rides[j][1] - rides[j][0] + rides[j][2]);
                j++;
            }
        }

        return dp[n];
    }
};