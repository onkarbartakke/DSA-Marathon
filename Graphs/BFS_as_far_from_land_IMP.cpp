#include <bits/stdc++.h>
/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1)
 is |x0 - x1| + |y0 - y1|.
*/
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {

        int r, c;
        r = grid.size();
        c = grid[0].size();

        queue<pair<int, int>> qu;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    qu.push({i + 1, j});
                    qu.push({i - 1, j});
                    qu.push({i, j + 1});
                    qu.push({i, j - 1});
                }
            }
        }

        int steps = 0;

        while (!qu.empty())
        {
            int sz = qu.size();

            steps++;

            while (sz--)
            {
                int i = qu.front().first;
                int j = qu.front().second;

                qu.pop();

                if (i >= 0 && j >= 0 && i < r && i < c && grid[i][j] == 0)
                {
                    grid[i][j] = steps;
                    qu.push({i + 1, j});
                    qu.push({i - 1, j});
                    qu.push({i, j + 1});
                    qu.push({i, j - 1});
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << grid[i][j] << " ";
            }

            cout << "\n";
        }

        if (steps == 1)
            return -1;
        else
            return steps - 1;
    }
};