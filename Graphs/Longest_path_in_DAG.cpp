#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void toposort(int u, vector<vector<int>>adj[], vector<bool>&visited, stack<int>&st)
{
    visited[u]=true;

    for(auto v : adj[u])
    {
        if(!visited[v[0]])
        toposort(v[0],adj,visited,st);
    }

    st.push(u);
}

vector<int> LongestPath(int V, vector<vector<int>>adj[], int src)
{
    stack<int>st;

    vector<bool>visited(V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        toposort(i,adj,visited,st);
    }

    vector<int>dist(V,INT_MIN);

    dist[src]=0;

    while(!st.empty())
    {
        int u=st.top();
        st.pop();

        if(dist[u]!=INT_MIN)
        {
            for(auto v : adj[u])
            {
                if(dist[v[0]] < dist[u] + v[1])
                dist[v[0]]=dist[u]+v[1];
            }
        }
    }

    return dist;
}

int main()
{
    int V,E,i;
    cout<<"Enter the num of verices : ";
    cin>>V;

    vector<vector<int>>adj[V];

    cout<<"Enter the num of edges : ";
    cin>>E;

    cout<<"\nEnter the Edges : \n";

    int u,v,w;
    for(i=0;i<E;i++)
    {
        cin>>u>>v;
        cin>>w;
        //u ---> v;

        adj[u].push_back({v,w});
    }

    cout<<"\nEnter the source vertex : ";
    int s;
    cin>>s;

    vector<int>LP=LongestPath(V,adj,s);

    cout<<"\nLongest Path from source "<<s<<" to all other vertices : \n\n";

    for(i=0;i<V;i++)
    {
        cout<<LP[i]<<" ";
    }
}

// is simi;ar manner shortest path can be calucaled
/*
By replacing INT_MIN by INT_MAX
and dist[v] > dist[u]+cost(u,v)
    dist[v]=dist[u]+ cost(u,v)
*/