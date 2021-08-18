#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
int timer=0;

void DFS(int u, vector<vector<int>>&adj, vector<bool>&visited ,vector<int>&InTime, vector<int>&OutTime)
{
	InTime[u]=timer;
	timer++;
	visited[u]=true;

	for(auto v : adj[u])
	{
		if(!visited[v])
		{
			DFS(v,adj,visited,InTime,OutTime);
		}
	}

	OutTime[u]=timer;
	timer++;
}

bool Present_in_subtree(int x, int y, vector<int>&InTime, vector<int>&OutTime)
{
	if(InTime[x]< InTime[y] && OutTime[x]>OutTime[y])
	return true;
	else
	return false;
}
int main()
{
	int n,i,j,k,q;
	cin>>n;

	vector<vector<int>>adj(n+1);

	for(i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);	
	}

	vector<int>InTime(n+1,-1);
	vector<int>OutTime(n+1,-1);

	vector<bool>visited(n+1,false);
	timer=1;
	DFS(1,adj,visited,InTime,OutTime);

	cin>>q;

	while(q--)
	{
		int x,y,dir;

		cin>>dir>>x>>y;

		if(dir==0)
		{
			if(Present_in_subtree(x,y,InTime,OutTime))
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else
		{
			if(Present_in_subtree(y,x,InTime, OutTime))
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}

	}
}