#include <bits/stdc++.h>

using namespace std;

/*
Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.
*/
class Solution
{
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void DFS(int r, int c, vector<vector<int>> &dp, vector<vector<int>> &grid, queue<pair<int, int>> &qu, int cost)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || dp[r][c] != INT_MAX)
            return;

        qu.push({r, c});
        dp[r][c] = cost;
        int next_dir = grid[r][c] - 1;

        DFS(r + dir[next_dir][0], c + dir[next_dir][1], dp, grid, qu, cost);
    }
    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> qu;
        DFS(0, 0, dp, grid, qu, 0);

        int cost = 0; 
        while (!qu.empty())
        {
            cost++;
            int sz = qu.size();

            while (sz--)
            {
                auto p = qu.front();
                qu.pop();

                int r = p.first, c = p.second;

                for (int j = 0; j < 4; j++)
                    DFS(r + dir[j][0], c + dir[j][1], dp, grid, qu, cost);
            }
        }

        return dp[n - 1][m - 1];
    }
};