#include <bits/stdc++.h>

using namespace std;
/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that 
you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 
 */
class Solution
{
    public:
    int cherryPickup(vector<vector<int>> &grid)
    {

        int i, j, k, ROWS, COLS;

        ROWS = grid.size();
        COLS = grid[0].size();

        vector<vector<vector<int>>> dp(ROWS, vector<vector<int>>(COLS, vector<int>(COLS, 0)));

        // LAST ROW

        for (i = 0; i < COLS; i++)
        {
            for (j = i; j < COLS; j++)
            {
                if (i == j)
                    dp[ROWS - 1][i][j] = max(dp[ROWS - 1][i][j], grid[ROWS - 1][i]);
                else
                    dp[ROWS - 1][i][j] = grid[ROWS - 1][i] + grid[ROWS - 1][j];
            }
        }

        int D[] = {-1, 0, 1};

        for (k = ROWS - 2; k >= 0; k--)
        {
            vector<int> row = grid[k];

            for (i = 0; i < COLS; i++)
            {
                for (j = i; j < COLS; j++)
                {
                    for (int x = 0; x < 3; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            if (i + D[x] < 0 || i + D[x] >= COLS || j + D[y] < 0 || j + D[y] >= COLS)
                                continue;

                            if (i == j)
                                dp[k][i][j] = max(dp[k][i][j], dp[k + 1][i + D[x]][j + D[y]] + row[i]);
                            else
                                dp[k][i][j] = max(dp[k][i][j], dp[k + 1][i + D[x]][j + D[y]] + row[i] + row[j]);
                        }
                    }
                }
            }
        }

        return dp[0][0][COLS - 1];
    }
};