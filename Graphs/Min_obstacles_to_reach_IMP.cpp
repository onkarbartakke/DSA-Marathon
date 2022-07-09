#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
/*
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the 
upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
*/
class Solution
{
public:
    class comp
    {
    public:
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[0] > b[0];
        }
    };

        int minimumObstacles1(vector<vector<int>>& grid) {//Dikstra Approach

            int n , m;
            n = grid.size();
            m = grid[0].size();

            vector<vector<int>>dist(n, vector<int>(m,INT_MAX));

            dist[0][0] = grid[0][0];

            priority_queue< vector<int> , vector<vector<int>> , comp>pq;

            pq.push({dist[0][0],0,0});

            while(!pq.empty())
            {
                auto v = pq.top();
                pq.pop();

                int obstacles = v[0];
                int i = v[1];
                int j = v[2];

                if(i == n-1 && j == m-1)
                    return obstacles;

                for(int k = 0 ; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx>=0 && ny>=0 && nx < n && ny < m && dist[nx][ny] > dist[i][j] + grid[nx][ny])
                    {
                        dist[nx][ny] = dist[i][j] + grid[nx][ny];
                        pq.push({dist[nx][ny] , nx, ny});
                    }
                }
            }

            return dist[n-1][m-1];
        }

    int minimumObstacles(vector<vector<int>> &grid) // 0-1 BFS Approach
    {

        int n, m;
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = grid[0][0];

        deque<pair<int, int>> dq;

        dq.push_back({0, 0});

        while (!dq.empty())
        {
            auto p = dq.front();
            dq.pop_front();

            int i = p.first, j = p.second;

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] > dist[i][j] + grid[nx][ny])
                {
                    dist[nx][ny] = dist[i][j] + grid[nx][ny];

                    if (grid[nx][ny])
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};

//https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/discuss/2088276/Two-methods-oror-0-1-bfs-oror-dijkastras-algo-oror100-fasteroror-resources-included