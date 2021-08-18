#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isCyclic_till(vector<vector<int>>&adjlst, int visited[], int curr)
{
    if(visited[curr]==2)
    return true;

    visited[curr]=1;
    int i;
    bool flag=false;
    for(i=0;i<adjlst[curr].size();i++)
    {
        if(visited[i]==1)
        visited[i]=2;
        else
        {
            flag=isCyclic_till(adjlst,visited,adjlst[curr][i]);
            if(flag)
            return true;
        }
    }

    visited[i]=0;
    return false;
}

bool isCyclic(vector<vector<int>>&adjlst, int v)
{
    int i,j;
    int visited[v]={0};

    bool flag=false;

    for(i=0;i<v;i++)
    {
        visited[i]=1;

        for(j=0;j<adjlst[i].size();j++)
        {
            flag=isCyclic_till(adjlst,visited,adjlst[i][j]);
            if(flag)
            return true;
        }

        visited[i]=0;
    }

    return false;
}

bool isCycle(int src, vector<vector<int>>&adjlst, vector<bool>&visited, int parent)
{
    if(visited[src])
    return true;

    visited[src]=true;

    for(auto i : adjlst[src])
    {
        if(i!=parent)
        {
            if(visited[i])
            return true;
            if(!visited[i] && isCycle(i,adjlst,visited,src))
            return true;
        }
    }

    return false;
}

int main()
{
    int i,j,v,e,x,y;

    cout<<"Enter the num of Vertices and Edges : ";
    cin>>v>>e;

    vector<vector<int>>adjlst(v);

    cout<<"\nEnter the Edges : ";

    for(i=0;i<e;i++)
    {
        cin>>x>>y;

        //x -- y
        adjlst[x].push_back(y);
        adjlst[y].push_back(x);
    }

    if(isCyclic(adjlst,v))
    {
        cout<<"\nGraph is Cyclic\n";
    }
    else
    {
        cout<<"\nGraph is not cyclic\n";
    }

    vector<bool>visited(v,false);
    bool cycle=false;
    for(i=0;i<v;i++)
    {
        if(!visited[i] && isCycle(i,adjlst,visited,-1))
        {
            cycle=true;
            break;
        }
    }

    if(cycle)
    {
        cout<<"\nGraph is Cyclic\n";
    }
    else
    {
         cout<<"\nGraph is not cyclic\n";
    }
}