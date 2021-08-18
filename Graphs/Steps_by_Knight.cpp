#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;


/*
Here, places where knight can go is like Unweighted graph, with unit distance(steps)
so here we nned to find shortest path len (steps) to target.
As it is Unweuighted we are able to use BFS here.
*/
class cell
{
    public:
    int x;
    int y;
    int dist;

    cell(int x1, int y1, int d)
    {
        x = x1;
        y = y1;
        dist = d;
    }
};

bool isSafe(int x, int y, int N)
{
    if (x < 1 || y < 1 || x > N || y > N)
        return false;

    return true;
}
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    int i, j, k, x, y, t;
    vector<vector<bool>> board(N + 1, vector<bool>(N + 1, false));

    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    queue<cell> qu;

    cell c(KnightPos[0], KnightPos[1], 0);

    qu.push(c);
    board[KnightPos[0]][KnightPos[1]] = true;

    while (!qu.empty())
    {
        cell t = qu.front();
        qu.pop();

        if (t.x == TargetPos[0] && t.y == TargetPos[1])
            return t.dist;

        for (i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if (isSafe(x, y, N) && !board[x][y])
            {
                board[x][y] = true;
                cell s(x, y, t.dist + 1);
                qu.push(s);
            }
        }
    }

    return -1;
}

int main()
{

}