#include<bits/stdc++.h>

using namespace std;

void DFS(int u, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;

    for (auto v : adj[u])
    {
        if (!visited[v])
            DFS(v, adj, visited, st);
    }

    st.push(u);
}

void DFS1(int u, vector<int> rev[], vector<bool> &visited, vector<int>&comp)
{
    visited[u] = true;
    comp.push_back(u);
    for (auto v : rev[u])
    {
        if (!visited[v])
            DFS1(v, rev, visited,comp );
    }
}

int kosaraju(int V, vector<int> adj[])
{
    //code here
    vector<bool> visited(V, false);

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj, visited, st);
        }
    }

    // memset(visited,false,V);
    for (int i = 0; i < V; i++)
        visited[i] = false;

    int count = 0;

    vector<int> rev[V];

    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            rev[j].push_back(i);
        }
    }

    vector<vector<int>>ans;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        if (!visited[curr])
        {
            count++;
            vector<int>comp;
            DFS1(curr, rev, visited,comp);
            sort(comp.begin(),comp.end());
            ans.push_back(comp);
        }
    }

    return count;
}

int main()
{
    
}