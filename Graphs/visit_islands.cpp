#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void visit(int x, int y, vector<vector<char>> &grid, int n, int m)
{
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != '1')
        return;

    grid[x][y] = '2';

    visit(x + 1, y, grid, n, m);
    visit(x, y + 1, grid, n, m);
    visit(x - 1, y, grid, n, m);
    visit(x, y - 1, grid, n, m);
    visit(x + 1, y + 1, grid, n, m);
    visit(x - 1, y - 1, grid, n, m);
    visit(x + 1, y - 1, grid, n, m);
    visit(x - 1, y + 1, grid, n, m);

    return;
}

int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int i, j, n, m;
    n = grid.size();
    m = grid[0].size();

    int count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                visit(i, j, grid, n, m);
            }
        }
    }

    return count;
}

int main()
{
    
}