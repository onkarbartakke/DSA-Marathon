#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void DFS(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;

    for (auto v : adj[u])
    {
        if (!visited[v])
            DFS(v, adj, visited);
    }
}
bool connected(int V, vector<int> adj[])
{
    int node = -1;

    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() > 0)
        {

            node = i;
            break;
        }
    }

    if (node == -1)
        return true;

    vector<bool> visited(V, false);

    DFS(node, adj, visited);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && adj[i].size() > 0)
            return false;
    }

    return true;
}
int isEularCircuit(int V, vector<int> adj[])
{
    // Code here

    if (!connected(V, adj))
        return 0;

    int odd = 0;

    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() % 2 == 1)
            odd++;
    }

    if (odd == 0)
        return 2;  // 2--> Eulerian circut (start = end vertex)

    if (odd == 2)   // 1 -> Eullerian Path (start != end )
        return 1;

    return 0;
}

int main()
{

}

/*
Eulerian Path is a path in graph that visits every edge exactly once. 
Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex
*/