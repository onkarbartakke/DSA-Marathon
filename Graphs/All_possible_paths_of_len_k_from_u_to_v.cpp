#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

//Dp solution

int MinimumWalk(vector<vector<int>> &graph, int u, int v, int k)
{
    // Code here

    int i, j, e, a;
    int V = graph.size();
    int dp[V][V][k + 1];

    for (e = 0; e <= k; e++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {

                dp[i][j][e] = 0;

                if (e == 0 && i == j)
                {
                    dp[i][j][e] = 1;
                }
                else if (e == 1 && graph[i][j])
                {
                    dp[i][j][e] = 1;
                }
                else if (e > 1)
                {
                    for (a = 0; a < V; a++)
                    {
                        if (graph[i][a])
                        {
                            dp[i][j][e] += dp[a][j][e - 1];
                        }
                    }
                }
            }
        }
    }

    return dp[u][v][k];
}



//Recursive sol

int Minwalk(vector<vector<int>>&graph, int u, int v, int k)
{
    int V=graph.size();

    if(k==0 && u==v)
    return 1;

    if(k==1 && graph[u][v])
    return 1;

    int count=0;
    for(int i=0;i<V;i++)
    {
        if(graph[u][i])
        count+=Minwalk(graph,i,v,k-1);
    }

    return count;
}

int main()
{
    
}