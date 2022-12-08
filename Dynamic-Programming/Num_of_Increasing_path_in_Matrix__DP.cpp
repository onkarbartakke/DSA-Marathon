#include <bits/stdc++.h>

using namespace std;
/*

You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

 
 */
#define mod 1000000007
class Solution
{
public:
    vector<vector<int>> dp;

    long long DFS(int i, int j, vector<vector<int>> &grd, int Curval)
    {
        if (i < 0 || j < 0 || i >= grd.size() || j >= grd[0].size() || grd[i][j] <= Curval)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long res = 0;

        res = 1 + DFS(i + 1, j, grd, grd[i][j]) + DFS(i, j + 1, grd, grd[i][j]) + DFS(i - 1, j, grd, grd[i][j]) + DFS(i, j - 1, grd, grd[i][j]);

        res = res % mod;

        dp[i][j] = res;

        return res;
    }
    int countPaths(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res = (DFS(i, j, grid, 0) + res) % mod;
            }
        }

        return res;
    }
};