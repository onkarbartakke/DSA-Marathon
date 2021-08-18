#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include<unordered_set>

using namespace std;

bool isCyclic(int v, vector<vector<int>>&adj, vector<bool>&visited, int parent)
{
    if(visited[v])
    return false;

    int i,j;
    vector<int>ver=adj[v];
    visited[v]=true;

    for(i=0;i<ver.size();i++)
    {
        if(!visited[ver[i]])
        {
            if(isCyclic(ver[i],adj,visited,v));
            return true;
        }
        else if(ver[i]!=parent)
        return true;
    }

    return false;
}

bool isTree(int V, int E, vector<vector<int>>&adj)
{
    vector<bool>visited(V,false);

    if(isCyclic(0,adj,visited,-1));
    return false;

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        return false;
    }

    return true;
}
int main()
{
    cout<<"Enter the Num of Vertices : ";
    int i,j,V,k,E;
    cin>>V;

    cout<<"Enter the num of Edges : ";
    cin>>E;

    cout<<"\nEnter the edges : \n";

    vector<vector<int>>adj(V);

    for(i=0;i<E;i++)
    {
        int x,y;
        cin>>x;
        cin>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

   

    if(isTree(V,E,adj))
    {
        cout<<"\nGiven graph is Tree";
    }
    else
    {
        cout<<"\nGiven Graph is not Tree";
    }
    
}