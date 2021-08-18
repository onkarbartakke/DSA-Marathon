#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

vector<int>Min_time(int V , vector<vector<int>>&adj, vector<int>&incoming)
{
    int i,j,k,time=0;
    map<int,int>mymap;

    queue<int>qu;

    for(i=1;i<=V;i++)
    {
        if(incoming[i]==0)
        qu.push(i);
    }
    vector<int>T(V+1);

    while(!qu.empty())
    {
        int size=qu.size();
        time++;

        while(size--)
        {
            int u=qu.front();
            qu.pop();
            T[u]=time;

            for(auto it : adj[u])
            {
                incoming[it]--;

                if(incoming[it]==0)
                {
                    qu.push(it);
                }
            }
        }
    }

    return T;
}

int main()
{
    int i,j,k,V,E;

    cout<<"Enter the Num of Vertices : ";
    cin>>V;

    vector<vector<int>>adj(V+1);
    cout<<"\nEnter the num of Edges : ";
    cin>>E;
    cout<<"\nEnter the Edges : \n";

    int u,v;
    // u --> v
    vector<int>incoming(V+1,0);

    for(i=0;i<E;i++)
    {
        cin>>u>>v;

        adj[u].push_back(v);
        incoming[v]++;
    }

    vector<int>ans=Min_time(V,adj,incoming);

    cout<<"\n\n";

    for(i=1;i<=V;i++)
    {
        cout<<ans[i]<<" ";
    }
}