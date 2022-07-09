#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void Tranjans(int u, int n, vector<int> &low, vector<int> &disc, vector<int> &parent, vector<int> adj[], vector<vector<int>> &ans)
    {
        static int time = 0;

        disc[u] = low[u] = time;
        time++;

        for (auto v : adj[u])
        {
            if (disc[v] == -1)
            {
                parent[v] = u;
                Tranjans(v, n, low, disc, parent, adj, ans);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u])
                    ans.push_back({u, v});
            }
            else if (v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<int> low(n, -1), disc(n, -1), parent(n, -1);

        vector<int> adj[n];

        for (auto c : connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++)
        {
            if (disc[i] == -1)
            {
                Tranjans(i, n, low, disc, parent, adj, bridges);
            }
        }

        return bridges;
    }
};