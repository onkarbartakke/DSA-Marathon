#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        int n = matrix.size();
        int m = matrix[0].size();

        int mx = 1;

        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[i][j] < matrix[nx][ny])
            {
                mx = max(mx, 1 + solve(nx, ny, matrix, dp));
            }
        }

        dp[i][j] = mx;

        return mx;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mx = max(mx, solve(i, j, matrix, dp));
            }
        }

        return mx;
    }
};