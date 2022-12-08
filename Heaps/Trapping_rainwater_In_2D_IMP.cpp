#include <bits/stdc++.h>

using namespace std;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int r = heightMap.size();
        int c = heightMap[0].size();

        int ans = 0;

        vector<bool> vis(r * c, false);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
                {
                    vis[i * c + j] = true;
                    pq.push({heightMap[i][j], i * c + j});
                }
            }
        }

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int i = p.second / c;
            int j = p.second % c;

            int h = p.first;
            int ii, jj;

            for (int k = 0; k < 4; k++)
            {
                ii = i + dx[k];
                jj = j + dy[k];

                if (ii >= 0 && ii < r && jj >= 0 && jj < c && !vis[ii * c + jj])
                {
                    ans += max(0, h - heightMap[ii][jj]);
                    pq.push({max(h, heightMap[ii][jj]), ii * c + jj});
                    vis[ii * c + jj] = true;
                }
            }
        }

        return ans;
    }
};


int main()
{
}