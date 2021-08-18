#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

vector<int> Dijkstra(int V , vector<vector<int>>adj1[], int src)
{
    vector<int>cost(V,INT_MAX);
   // vector<bool>visited(V,false);

    set< pair<int,int> >stp;

    for(int i=0;i<V;i++)
    {
        if(i!=src)
        {
            stp.insert({INT_MAX,i});
        }
    }

    stp.insert({0,src});

    while(!stp.empty())
    {
        pair<int,int>p=(*stp.begin());
        int u=p.second;
        cost[u]=p.first;
        stp.erase(p);

        for( auto v : adj1[u])
        {
            if( cost[u]!=INT_MAX && (cost[v[0]] > cost[u] + v[1]) )
            {
                stp.erase( {cost[v[0]] , v[0]} );
                cost[v[0]]=cost[u]+v[1];
               stp.insert( {cost[v[0]] , v[0]} );
            }
        }
    }

    return cost;

}
void reverse(vector<vector<int>>&adj, vector<vector<int>>adj1[], int V)
{
    int i;
    for(i=0;i<V;i++)
    {
        for(auto v : adj[i])
        {
            adj1[i].push_back({v,0});
            adj1[v].push_back({i,1});
        }
    }
}

int main()
{
    int V,E,i,j;

    cout<<"Enter the num of Vertices and Edges : ";
    cin>>V>>E;

    vector<vector<int>>adj(V);
    
    cout<<"Enter the Edges : \n";

    for(i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;

        //u --> v

        adj[u].push_back(v);
    }

    cout<<"\nEnter the source and the destination : ";
    int src,dst;
    cin>>src>>dst;

    vector<vector<int>>adj1[V];

    reverse(adj,adj1,V);

    vector<int>cost=Dijkstra(V,adj1,src);

    cout<<"\nNum of Edges required to reverse : "<<cost[dst];
}