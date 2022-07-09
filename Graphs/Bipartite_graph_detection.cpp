#include <bits/stdc++.h>
#define Size 1000
using namespace std;

vector<vector<int>> adjlst;

//DFS Approach
vector<int> colour(Size, -1);
vector<int> visited(Size, 0);
bool bipartite;
void color_it(int u, int c)
{
    if (colour[u] != -1 && colour[u] != c)
    {
        bipartite = false;
        return;
    }

    colour[u] = c;

    if (visited[u] == 1)
        return;

    visited[u] = 1;
    for (auto i : adjlst[u])
    {
        color_it(i, c ^ 1);
    }
}

int main()
{
    int i, j, k, e, v, x, y;
    cout << "Enter the total num of Vertices and Edges : ";
    cin >> v >> e;

    bipartite = true;
    adjlst = vector<vector<int>>(v);

    cout << "Enter the Edges : \n";

    for (i = 0; i < e; i++)
    {
        cin >> x >> y;

        adjlst[x].push_back(y);
        adjlst[y].push_back(x);
    }

    for (i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            color_it(i, 0);
        }
    }

    if (bipartite)
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is not Bpartite\n";
}

//BFS approach

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        int V = graph.size();

        vector<int> col(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (col[i] == 0)
            {
                col[i] = 1;
                queue<int> qu;
                qu.push(i);

                while (!qu.empty())
                {
                    int u = qu.front();
                    qu.pop();

                    for (auto v : graph[u])
                    {
                        if (col[v] == 0)
                        {
                            col[v] = -1 * col[u];
                            qu.push(v);
                        }
                        else if (col[u] == col[v])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};