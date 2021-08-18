#include <iostream>
#include <vector>
#include <stack>
#include<climits>
#include <map>
#include <set>

using namespace std;

int spanningTree(int V, vector<vector<int>>&adj)
{
    // code here
    int i, j, k, u, v, src;

    src = 0;
    int parent[V];
    //bool mst[V] = {false};
    vector<bool>mst(V,false);
    vector<int> dist(V, INT_MAX);

    set<pair<int, int>> st;
    

    for (i = 1; i < V; i++)
    {
        st.insert({INT_MAX, i});
    }

    st.insert({0, src});
    dist[src] = 0;
    while (!st.empty())
    {
        pair<int, int> p = (*st.begin());
        st.erase(p);
        mst[p.second] = true;

        u = p.second;
        for (v = 0; v < V; v++)
        {
            if (adj[u][v] && dist[v] > adj[u][v] && mst[v] == false)
            {
                parent[v] = u;
                st.erase({dist[v], v});
                dist[v] = adj[u][v];
                st.insert({dist[v], v});
            }
        }
    }

    int sum = 0;
    cout<<"\nEdges in Min spanning tree are : \n";
    for (i = 1; i < V; i++)
    {
        sum += adj[i][parent[i]];

        cout<<i<<" -- "<<parent[i]<<"\n";
    }

   
    

    return sum;
}
int main()
{
    int V,i,j,u,v,w;

    cout<<"Enter the num of vertices : ";
    cin>>V;

    vector<vector<int>>adj(V,vector<int>(V,0));

    int E;
    cout<<"\nEnter the num of Edges : ";
    cin>>E;
    cout<<"Enter edges and values u, v, w : \n";

    for(i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        //cout<<i<<"\n";
        adj[u][v]=w;
        adj[v][u]=w;
    }

    cout<<"\nGraph is : \n";

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    int sum=spanningTree(V,adj);

    cout<<"\nMin spanning Tree sum is "<<sum;
}