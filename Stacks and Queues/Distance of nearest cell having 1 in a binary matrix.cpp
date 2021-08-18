#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int n, m, i, j;
    n = grid.size();
    m = grid[0].size();

    queue<pair<int, int>> qu;

    vector<vector<int>> ans(n, vector<int>(m, INT_MAX - 1));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ans[i][j] = 0;
                qu.push({i, j});
            }
        }
    }

    while (!qu.empty())
    {
        i = qu.front().first;
        j = qu.front().second;
        qu.pop();

        if (i + 1 < n && ans[i + 1][j] > ans[i][j] + 1)
        {
            ans[i + 1][j] = ans[i][j] + 1;
            qu.push({i + 1, j});
        }

        if (i - 1 >= 0 && ans[i - 1][j] > ans[i][j] + 1)
        {
            ans[i - 1][j] = ans[i][j] + 1;
            qu.push({i - 1, j});
        }

        if (j + 1 < m && ans[i][j + 1] > ans[i][j] + 1)
        {
            ans[i][j + 1] = ans[i][j] + 1;
            qu.push({i, j + 1});
        }

        if (j - 1 >= 0 && ans[i][j - 1] > ans[i][j] + 1)
        {
            ans[i][j - 1] = ans[i][j] + 1;
            qu.push({i, j - 1});
        }
    }

    return ans;
}


int main()
{
    
}