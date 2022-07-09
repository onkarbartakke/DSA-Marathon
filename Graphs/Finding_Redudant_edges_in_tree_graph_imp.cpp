#include <bits/stdc++.h>

using namespace std;

/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an 
edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, 
return the answer that occurs last in the input.

 
 */
class Solution
{
public:
    void DFS(vector<vector<int>> &g, int par, int curr, vector<bool> &vis, unordered_set<int> &cyc, int &cycle_start)
    {
        if (vis[curr] == true)
        {
            cycle_start = curr;
            cyc.insert(curr);
            return;
        }

        vis[curr] = true;

        for (auto v : g[curr])
        {
            if (v == par)
                continue;

            if (cyc.empty())
                DFS(g, curr, v, vis, cyc, cycle_start);

            if (cycle_start != -1 && curr != cycle_start)
            {
                cyc.insert(curr);
                return;
            }

            if (curr == cycle_start)
            {
                cycle_start = -1;
                return;
            }
        }

        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {

        unordered_set<int> cycle;

        int n = edges.size();
        vector<vector<int>> g(n + 1);

        for (auto E : edges)
        {
            g[E[0]].push_back(E[1]);
            g[E[1]].push_back(E[0]);
        }

        int cycle_start = -1;

        vector<bool> vis(n + 1, false);
        DFS(g, -1, 1, vis, cycle, cycle_start);

        for (int i = n - 1; i >= 0; i--)
        {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
                return edges[i];
        }

        return {};
    }
};