#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclic_till(vector<vector<int>> &adjlst, int v, vector<bool> &visited, int curr)
{
    if (visited[curr] == true)
        return true;

    visited[curr] = true;
    int i, j;
    bool flag = false;
    for (i = 0; i < adjlst[curr].size(); i++)
    {
        flag = isCyclic_till(adjlst, v, visited, adjlst[curr][i]);
        if (flag == true)
            return true;
    }

    visited[curr] = false;

    return false;
}

bool isCyclic(vector<vector<int>> &adjlst, int v)
{
    vector<bool> visited(v, false);
    int i, j;
    bool flag = false;

    for (i = 0; i < v; i++)
    {
        visited[i] = true;

        for (j = 0; j < adjlst[i].size(); j++)
        {
            flag = isCyclic_till(adjlst, v, visited, adjlst[i][j]);

            if (flag == true)
                return true;
        }

        visited[i] = false;
    }

    return false;
}

int main()
{
    int i, j, v, e, x, y;

    cout << "Enter the num of Vertices and Edges : ";
    cin >> v >> e;

    vector<vector<int>> adjlst(v);

    cout << "\nEnter the Edges : ";

    for (i = 0; i < e; i++)
    {
        cin >> x >> y;

        //x --> y
        adjlst[x].push_back(y);
    }

    if (isCyclic(adjlst, v))
    {
        cout << "\nGraph is Cyclic\n";
    }
    else
    {
        cout << "\nGraph is not cyclic\n";
    }
}

//Optimised DFS Approach using callstack and visited array

bool Cyclic_until(int curr, vector<bool> &inTheCall, vector<int> adj[], vector<bool> &visited)
{
    if (inTheCall[curr])
        return true;

    inTheCall[curr] = true;
    visited[curr] = true;
    for (auto it : adj[curr])
    {
        if (!visited[it] && Cyclic_until(it, inTheCall, adj, visited))
            return true;

        if (inTheCall[it])
            return true;
    }

    inTheCall[curr] = false;

    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> inTheCall(V, false);
    vector<bool> visited(V, false);
    int i, j, k;

    for (i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (Cyclic_until(i, inTheCall, adj, visited))
                return true;
        }
    }

    return false;
}

/*
BFS Approach using Khans Algo

The idea is to simply use Kahn’s algorithm for Topological Sorting

Steps involved in detecting cycle in a directed graph using BFS.
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the graph
 and initialize the count of visited nodes as 0.
Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
Step-3: Remove a vertex from the queue (Dequeue operation) and then. 



Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 4: Repeat Step 3 until the queue is empty.
Step 5: If count of visited nodes is not equal to the number of nodes in the graph has cycle, otherwise not.
*/