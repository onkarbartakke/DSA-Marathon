#include <iostream>
#include<vector>
#include<queue>
using namespace std;

struct timepos
{
    int timeFrame;
    int r;
    int c;
};

int orangesRotting(vector<vector<int>> &grid)
{

    // Code here
    int i, j, n;
    n = grid.size();
    int m = grid[0].size();
    queue<timepos> qu;

    int t = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {

                timepos tp;
                tp.timeFrame = 0;
                tp.r = i;
                tp.c = j;
                qu.push(tp);
            }
        }
    }
    int tf = 0;

    while (!qu.empty())
    {
        timepos tp = qu.front();
        qu.pop();
        i = tp.r;
        j = tp.c;
        tf = tp.timeFrame;
        timepos adj;

        if (i + 1 < n && grid[i + 1][j] == 1)
        {
            grid[i + 1][j] = 2;
            adj.timeFrame = tf + 1;
            adj.r = i + 1;
            adj.c = j;
            qu.push(adj);
        }

        if (i - 1 >= 0 && grid[i - 1][j] == 1)
        {
            grid[i - 1][j] = 2;
            adj.timeFrame = tf + 1;
            adj.r = i - 1;
            adj.c = j;
            qu.push(adj);
        }

        if (j + 1 < m && grid[i][j + 1] == 1)
        {
            grid[i][j + 1] = 2;
            adj.timeFrame = tf + 1;
            adj.r = i;
            adj.c = j + 1;
            qu.push(adj);
        }

        if (j - 1 >= 0 && grid[i][j - 1] == 1)
        {
            grid[i][j - 1] = 2;
            adj.timeFrame = tf + 1;
            adj.r = i;
            adj.c = j - 1;
            qu.push(adj);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return tf;
}

int main()
{
}