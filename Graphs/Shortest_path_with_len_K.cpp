#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int shortestPath(int graph[][V], int u, int v, int k)
{
    // Base cases
    if (k == 0 && u == v)
        return 0;
    if (k == 1 && graph[u][v] != INF)
        return graph[u][v];
    if (k <= 0)
        return INF;

    // Initialize result
    int res = INF;

    // Go to all adjacents of u and recur
    for (int i = 0; i < V; i++)
    {
        if (graph[u][i] != INF && u != i && v != i)
        {
            int rec_res = shortestPath(graph, i, v, k - 1);
            if (rec_res != INF)
                res = min(res, graph[u][i] + rec_res);
        }
    }
    return res;
}

// DP solution

int shortestPath(int graph[][V], int u, int v, int k)
{
    // Table to be filled up using DP. The value sp[i][j][e] will store
    // weight of the shortest path from i to j with exactly k edges
    int sp[V][V][k + 1];

    // Loop for number of edges from 0 to k
    for (int e = 0; e <= k; e++)
    {
        for (int i = 0; i < V; i++) // for source
        {
            for (int j = 0; j < V; j++) // for destination
            {
                // initialize value
                sp[i][j][e] = INF;

                // from base cases
                if (e == 0 && i == j)
                    sp[i][j][e] = 0;
                if (e == 1 && graph[i][j] != INF)
                    sp[i][j][e] = graph[i][j];

                //go to adjacent only when number of edges is more than 1
                if (e > 1)
                {
                    for (int a = 0; a < V; a++)
                    {
                        // There should be an edge from i to a and a
                        // should not be same as either i or j
                        if (graph[i][a] != INF && i != a &&
                            j != a && sp[a][j][e - 1] != INF)
                            sp[i][j][e] = min(sp[i][j][e], graph[i][a] +
                                                               sp[a][j][e - 1]);
                    }
                }
            }
        }
    }
    return sp[u][v][k];
}
int main()
{
}