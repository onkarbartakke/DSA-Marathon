#include<bits/stdc++.h>

using namespace std;


vector<int>parent(100000);


vector<int>rank(100000);


void makeSet(int n)
{
    for(int i = 1; i <=n ; i++)
    parent[i] = i;

    for(int i = 1 ; i <= n ; i++)
    rank[i] = 0;
}

int findParent(int node)
{
    if(node == parent[node])
    return node;
    else 
    return parent[node] = findParent(parent[node]);
}


void Union(int u , int v)
{
    u = findParent(u);
    v = findParent(v);

    if(rank[u] < rank[v])
    parent[u] = v;
    else if(rank[v] < rank[u])
    parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}


int main()
{
    int n,e;

    cin>>n;


}