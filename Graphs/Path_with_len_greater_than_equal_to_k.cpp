#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
vector<int>ans;

bool path_K(int u, vector<vector<int>> adj[], vector<bool> &visited, int k)
{
    if (k <= 0)
        return true;

    for (auto v : adj[u])
    {
        if (!visited[v[0]])
        {
            visited[v[0]] = true;

            if (v[1] >= k)
                return true;

            if (path_K(v[0], adj, visited, k - v[1]))
            {
                ans.push_back(v[0]);
                //cout<<k<<" --> "<<v[0]<<" --> "<<(k-v[1])<<"\n";
                return true;
            }

            visited[v[0]] = false;
        }
    }

    return false;
}
bool pathMoreThanK(int V, int E, int k, int *a)
{
    //  Code Here
    vector<vector<int>> adj[V];
    int j = 0;
    for (int i = 0; i < E; i++)
    {

        int u = a[j];
        int v = a[j + 1];
        int w = a[j + 2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        j = j + 3;
    }

    vector<bool> visited(V, false);

    visited[0] = true;

    for (auto v : adj[0])
    {
        if (!visited[v[0]])
        {
            if (v[1] >= k)
                return true;

            visited[v[0]]=true;
            if (path_K(v[0], adj, visited, k - v[1]))
            {
                ans.push_back(v[0]);
                ans.push_back(0);
               // cout<<k<<" --> "<<v[0]<<" --> "<<(k-v[1])<<"\n";
                return true;
            }

            visited[v[0]] = false;
        }
    }

    return false;
}

int main()
{
    int V,E,i,j,k;
    cout<<"\nEnter the num of Vertices and Edges : ";
    cin>>V>>E;
    cout<<"\nEnter the k : ";
    cin>>k;
    cout<<"\nEnter the cost array : \n";

    int a[3*E];

    for(i=0;i<3*E;i++)
    {
        cin>>a[i];
    }

    cout<<"\n\n";
    if(pathMoreThanK(V,E,k,a))
    {
        for(auto it=ans.end()-1 ; it>=ans.begin(); it--)
        {
            cout<<(*it)<<" ";
        }
    }
}