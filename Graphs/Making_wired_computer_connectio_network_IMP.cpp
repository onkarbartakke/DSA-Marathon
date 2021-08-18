#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void DFS(int src, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[src] = true;

    for (int i = 0; i < adj[src].size(); i++)
    {
        int v = adj[src][i];

        if (!visited[v])
        {
            DFS(v, adj, visited);
        }
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{

    int i, j, k, Edges = 0, components = 0;

    vector<vector<int>> adj(n);
    for (i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

        Edges++;
    }

    vector<bool> visited(n, false);

    for (i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            DFS(i, adj, visited);
            components++;
        }
    }

    if (Edges < (n - 1))
        return -1;

    int redudant = (Edges) - ((n - 1) - (components - 1));

    if (redudant < components - 1)
        return -1;

    return (components - 1);
}

int main()
{
    
}