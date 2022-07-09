#include<bits/stdc++.h>

using namespace std;

void DFS(int u, vector<int> &low, vector<int> &disc, vector<bool> &inStack, stack<int> &st, vector<vector<int>> &ans, vector<int> adj[])
{
    static int time = 0;
    low[u] = disc[u] = time;
    time++;

    st.push(u);
    inStack[u] = true;

    for (auto v : adj[u])
    {
        if (disc[v] == -1)
        {
            DFS(v, low, disc, inStack, st, ans, adj);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u])
    {
        vector<int> v;

        while (st.top() != u)
        {
            v.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
        }

        v.push_back(st.top());
        inStack[st.top()] = false;
        st.pop();

        sort(v.begin(), v.end());
        ans.push_back(v);
    }
}

vector<vector<int>> tarjans(int V, vector<int> adj[])
{
    //code here
    vector<vector<int>> ans;

    vector<bool> inStack(V, false);

    vector<int> low(V, -1);
    vector<int> disc(V, -1);

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            DFS(i, low, disc, inStack, st, ans, adj);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

}

/*
A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected
 component (SCC) 
of a directed graph is a maximal strongly connected subgraph. For example, 
there are 3 SCCs in the following graph.
*/