#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void DFS(int u, vector<int>&low, vector<int>&disc, vector<bool>&AP, vector<int>adj[], vector<int>&parent)
{
    static int time=0;
    int children=0;

    low[u]=disc[u]=time;
    time++;

    for(auto v : adj[u])
    {
        if(disc[v]==-1)
        {
            children++;
            parent[v]=u;
            DFS(v,low,disc,AP,adj,parent);
            low[u]=min(low[u],low[v]);

            if(parent[u]==-1 && children>1) //Case 1
            AP[u]=true;

            if(parent[u]!=-1 && low[v]>=disc[u]) //Case 2
            AP[u]=true;
        }
        else if(parent[u]!=v)
        {
            low[u]=min(low[u], disc[v]);
        }

    }
}

vector<int> FindCutVertex(int V, vector<int>adj[])
{
    int i,j;
    vector<int>disc(V,-1);
    vector<int>low(V,-1);

    vector<bool>AP(V,false);
    vector<int>parent(V,-1);
    for(i=0;i<V;i++)
    {
        if(disc[i]==-1)
        {
            DFS(i,low,disc,AP,adj,parent);
        }
    }

    vector<int>ans;

    for(i=0;i<V;i++)
    {
        if(AP[i])
        ans.push_back(i);
    }

    return ans;
}
int main()
{

}