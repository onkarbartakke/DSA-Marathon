#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void DFS(int u, vector<int>&low, vector<int>&disc, vector<int>adj[] ,vector<int>&parent, vector<pair<int,int>>&Bridges)
{
    static int time=0;
    low[u]=disc[u]=time;
    time++;

    for(auto v: adj[u])
    {
        if(disc[v]==-1)
        {
            parent[v]=u;
            DFS(v,low,disc,adj,parent,Bridges);
            low[u]=min(low[u],low[v]);

            if(low[v] > disc[u])
            {
                Bridges.push_back({u,v});
            }
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],disc[v]);
        }
    }
}


void Bridges(int V, vector<int>adj[])
{
    int i;
    vector<int>disc(V,-1);
    vector<int>low(V,-1);

    vector<int>parent(V,-1);

    vector<pair<int,int>>Bridges;

    for(i=0;i<V;i++)
    {
        if(disc[i]==-1)
        {
            DFS(i,low,disc,adj,parent,Bridges);
        }
    }
}

int main()
{

}