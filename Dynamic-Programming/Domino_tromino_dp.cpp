#include <bits/stdc++.h>

using namespace std;
/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally 
adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
*/
class Solution
{
    public:
    const long int mod = 1e9 + 7;
    int len;

    int f(int ind, bool space, vector<vector<int>> &dp)
    {
        if (ind == len + 1)
        {
            if (space)
                return 0;
            else
                return 1;
        }

        if (ind > len + 1)
            return 0;

        if (dp[ind][space] != -1)
            return dp[ind][space];

        long int cnt = 0;

        if (space)
        {
            cnt += f(ind + 1, true, dp);
            cnt += f(ind + 1, false, dp);
        }
        else
        {
            cnt += f(ind + 1, false, dp);
            cnt += f(ind + 2, false, dp);
            cnt += 2 * f(ind + 2, true, dp);
        }

        cnt %= mod;
        dp[ind][space] = cnt;

        return dp[ind][space];
    }

    int numTilings(int n)
    {

        len = n;

        vector<vector<int>> dp(len + 1, vector<int>(2, -1));

        f(1, false, dp);
        return dp[1][false];
    }
};