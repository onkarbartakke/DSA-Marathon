#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include<algorithm>
#include <queue>
#include <stack>
#include<list>
#include <map>
#include <set>

using namespace std;
class  Graph
{
    public:
    int V;
    list<int>*adj;

    Graph(int v)
    {
       this->V=v;
       adj=new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);

        //cout<<u<<" -- "<<v<<"\n";
    }

    void removeEdge(int u, int v)
    {
        list<int>::iterator it=find(adj[u].begin(),adj[u].end(),v);
        (*it)=-1;

        it=find(adj[v].begin(),adj[v].end(),u);
        (*it)=-1;
    }

    int DFS_count(int v, bool visited[])
    {
        visited[v]=true;
        int count=1;
        list<int>::iterator it;

        for(it=adj[v].begin();it!=adj[v].end();it++)
        {
            if((*it)!=-1 && !visited[(*it)])
            count+=(DFS_count(*it,visited));
        }

        return count;
    }


};

bool isValidEdges(int u, int v, Graph g)
{
    int count=0;
    list<int>::iterator it;

    for(it=g.adj[u].begin();it!=g.adj[u].end();it++)
    {
        int v=*it;

        if(v!=-1)
        count++;
    }

    if(count==1)
    return true;

    bool visited[g.V]={false};

    memset(visited,false,g.V);

    int c1=g.DFS_count(u,visited);

    g.removeEdge(u,v);
    memset(visited,false,g.V);
    int c2=g.DFS_count(u,visited);

    g.addEdge(u,v);

    if(c1>c2)
    return false;
    else
    return true;
}
void printEuler(Graph g, int u)
{ 
    list<int>::iterator it;

    for(it=g.adj[u].begin();it!=g.adj[u].end();it++)
    {
        int v=(*it);

        if(v!=-1 && isValidEdges(u,v,g))
        {
            cout<<u<<" -- "<<v<<"  ";
            g.removeEdge(u,v);
            printEuler(g,v);
        }
    }
}
void PrintEulerPath(Graph g)
{
    int odd=0,u;

    for(int  i=0;i<(g.V);i++)
    {
        if(g.adj[i].size()&1)
        {
            u=i;
            odd++;
        }
    }

    if(odd>2)
    {
        cout<<"Euler path dosent Exits\n";
        return;
    }

    printEuler(g,u);
}
int main()
{
    int n,V,E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"\nEnter the Number of Edges : ";
    cin>>E;

    Graph g(V);
    cout<<"Enter the Edges : \n";
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;

        //u <--> v
        g.addEdge(u,v);

       /// cout<<i<<"\n";
    }

    //Graph must be connected
    // if all Edges have even degree Euler cycle exits, that Euler circuit in graph
    // If only 2 Edges have odd degree then Euler Path Exits

    PrintEulerPath(g);

}