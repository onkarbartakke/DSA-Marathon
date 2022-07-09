#include <bits/stdc++.h>

using namespace std;
/*
You are given an m x n binary grid grid where 1 represents land and 0 represents water. 
An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 
 */
class Solution
{
public:
    void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] == true || grid[i][j] == 0)
            return;

        vis[i][j] = true;

        DFS(grid, i + 1, j, vis);
        DFS(grid, i, j + 1, vis);
        DFS(grid, i - 1, j, vis);
        DFS(grid, i, j - 1, vis);

        return;
    }
    int get_count(vector<vector<int>> &grid)
    {
        int n, m;

        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int islands = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == false)
                {
                    DFS(grid, i, j, vis);
                    islands++;
                }
            }
        }

        return islands;
    }
    int minDays(vector<vector<int>> &grid)
    {

        int islands = get_count(grid);

        if (islands > 1 || islands == 0)
            return 0;

        int n, m;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;

                    islands = get_count(grid);

                    grid[i][j] = 1;

                    if (islands > 1 || islands == 0)
                        return 1;
                }
            }
        }

        return 2;
    }
};