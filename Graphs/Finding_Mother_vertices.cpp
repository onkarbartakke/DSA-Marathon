#include <bits/stdc++.h>

using namespace std;
void DFS(int u, vector<bool> &vis, vector<vector<int>> &adj)
{
    if (vis[u])
        return;

    vis[u] = true;
   // cout<<u<<" == \n";
    for (auto v : adj[u])
    {
        //cout<<v<<" -- ";
        if (!vis[v])
            DFS(v, vis, adj);
    }
}

vector<vector<int>> Transpose(vector<vector<int>> &adj)
{
    int N = adj.size();

    vector<vector<int>> tp(N);
    //cout<<"Inside Tp\n";

    for (int i = 1; i < N; i++)
    {
        //cout<<i<<"\n";
        if(adj[i].size() == 0)
        continue;
        for (auto u : adj[i])
        {
            tp[u].push_back(i);
        }
    }

    return tp;
}

int captainAmerica(int N, int M, vector<vector<int>> &V)
{
    // Code Here
   // cout << "start\n";
    vector<vector<int>> adj(N + 1);
    //cout << "before for";
    for (auto e : V)
    {
        if(e.size() == 0)
        break;

        //cout << e[0] << " " << e[1] << "\n";
        adj[e[0]].push_back(e[1]);
        //cout << "]";
    }

    vector<bool> vis(N + 1, false);
    vector<vector<int>> tp = Transpose(adj);
    int mv = -1;
    //cout<<"1st dfs\n";
    for (int i = 1; i <= N; i++)
    {
        //cout<<i<<"\n";
        if (!vis[i])
        {
            DFS(i, vis, tp);
            mv = i;
        }
    }

    if (mv == -1)
        return 0;

    vector<bool>visit(N+1,false);
    DFS(mv,visit,tp);

    for(int i = 1 ; i <= N ; i++)
    {
        if(!visit[i])
        return 0;
    }
    //cout << "Before TP\n";

   // vector<vector<int>> tp = Transpose(adj);

    //cout << "After TP\n";
    vector<bool> visi(N + 1, false);

    //cout<<"DFS on MV\n";
    DFS(mv, visi, adj);

    int count = 0;

    for (int i = 1; i <= N; i++)
    {
        if (visi[i])
            count++;
    }

    return count;
}


int main()
{
    int n,m;

    cin>>n>>m;

    vector<vector<int>>V(m+1);

    for(int i = 0 ; i < m ; i++)
    {
        int a,b;
        cin>>a>>b;

        V[i].push_back(a);
        V[i].push_back(b);
    }

    cout<<captainAmerica(n,m,V);

}