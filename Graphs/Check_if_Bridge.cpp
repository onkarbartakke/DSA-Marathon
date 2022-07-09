#include <bits/stdc++.h>

using namespace std;

int vis[100001];
/*
Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., 
removing the edge disconnects the graph.
*/
int dfs(int i, vector<int> adj[], int c, int d)
{

    vis[i] = 1;

    for (auto x : adj[i])
    {
        if (i == c && x == d)
            continue;
        if (!vis[x])
            dfs(x, adj, c, d);
    }

    return 0;
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    // Code here
    for (int i = 0; i < V; i++)
        vis[i] = 0;

    dfs(c, adj, c, d);

    return (!vis[d]);
}

int main()
{
    int u,v;
    cout<<"Enter";
}