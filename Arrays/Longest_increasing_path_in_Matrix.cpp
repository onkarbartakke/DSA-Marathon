#include <bits/stdc++.h>

using namespace std;

/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or
 move outside the boundary (i.e., wrap-around is not allowed).


 */

// BFS Toposort solution
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> InDeg(n, vector<int>(m, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[i][j] < matrix[nx][ny])
                        InDeg[nx][ny]++;
                }
            }
        }

        int path_len = 0;

        queue<pair<int, int>> qu;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (InDeg[i][j] == 0)
                    qu.push({i, j});
            }
        }

        while (!qu.empty())
        {
            int sz = qu.size();
            while (sz--)
            {
                auto p = qu.front();
                qu.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = p.first + dx[k];
                    int ny = p.second + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] > matrix[p.first][p.second])
                    {
                        InDeg[nx][ny]--;

                        if (InDeg[nx][ny] == 0)
                            qu.push({nx, ny});
                    }
                }
            }

            path_len++;
        }

        return path_len;
    }
};

/*
We regard

a cell in the matrix as a node,
a directed edge from node x to node y if x and y are adjacent and x's value < y's value
Then a graph is formed.

No cycles can exist in the graph, i.e. a DAG is formed.

The problem becomes to get the longest path in the DAG.

Topological sort can iterate the vertices of a DAG in the linear ordering.

Using Kahn's algorithm(BFS) to implement topological sort while counting the levels can give us the longest chain of nodes in the DAG.


*/

// Another is DFS + DP approach

class Solution1
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