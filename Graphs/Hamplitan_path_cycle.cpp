#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

bool isSafe(vector<int> &path, vector<vector<bool>> &G, int pos, int v)
{
    if (G[path[pos - 1]][v] == false)
        return false;

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool HamPathUntil(int N, vector<vector<bool>> &G, vector<int> &path, int pos)
{
    if (pos == N - 1)
    {
        for (int v = 1; v <= N; v++)
        {
            if (isSafe(path, G, pos, v))
            {
                path[pos] = v;
                return true;
            }

            path[pos] = -1;
        }

        return false;
    }

    for (int v = 1; v <= N; v++)
    {
        if (isSafe(path, G, pos, v))
        {
            path[pos] = v;

            if (HamPathUntil(N, G, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}
bool HamPath(int N, vector<vector<bool>> &G)
{
    int start = 1;
    vector<int> path(N + 1, -1);

    path[0] = start;

    for (int v = 1; v <= N; v++)
    {
        path[0] = v;

        if (HamPathUntil(N, G, path, 1))
            return true;

        path[0] = -1;
    }

    return false;
}
bool check(int N, int M, vector<vector<int>> Edges)
{
    // code hereb
    int i, j, k;
    vector<vector<bool>> G(N + 1, vector<bool>(N + 1, false));

    for (i = 0; i < M; i++)
    {
        int u = Edges[i][0];
        int v = Edges[i][1];

        G[u][v] = true;
        G[v][u] = true;
    }

    int start = 1;

    if (HamPath(N, G))
        return true;
    else
        return false;
}

// For Ham- cycle any point can be starting point

bool isSafe(vector<int> &path, vector<vector<bool>> &G, int pos, int v)
{
    if (G[path[pos - 1]][v] == false)
        return false;

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool HamCycleUntil(int N, vector<vector<bool>> &G, vector<int> &path, int pos)
{
    if (pos == N)
    {
        if(G[path[pos-1]][path[0]])
        return true;

        else 
        return false;
    }

    for (int v = 1; v <= N; v++)
    {
        if (isSafe(path, G, pos, v))
        {
            path[pos] = v;

            if (HamCycleUntil(N, G, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}
bool HamCycle(int N, vector<vector<bool>> &G)
{
    int start = 1;
    vector<int> path(N + 1, -1);

    path[0] = start;

        if (HamCycleUntil(N, G, path, 1))
            return true;

    return false;
}
bool check(int N, int M, vector<vector<int>> Edges)
{
    // code hereb
    int i, j, k;
    vector<vector<bool>> G(N + 1, vector<bool>(N + 1, false));

    for (i = 0; i < M; i++)
    {
        int u = Edges[i][0];
        int v = Edges[i][1];

        G[u][v] = true;
        G[v][u] = true;
    }

    int start = 1;

    if (HamCycle(N, G))
        return true;
    else
        return false;
}


/*
Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. A Hamiltonian cycle
 (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in the graph) from the last 
 vertex to the first vertex of the Hamiltonian Path.
*/