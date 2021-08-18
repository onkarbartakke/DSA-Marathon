#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

void DFS(int u, vector<int>&parent, vector<int>&low, vector<int>&disc, vector<vector<int>>&edges, bool &b)
{
	static int time=0;
	
	if(b==true)
		return;
	
	low[u]=disc[u]=time;
	time++;
	
	for(auto v : edges[u])
	{
		if(b==true)
			return;
		
		if(disc[v]==-1)
		{
			parent[v]=u;
			DFS(v,parent,low,disc,edges,b);
			low[u]=min(low[u],low[v]);
				
				if(low[v] > disc[u])
				{
					b=true;
					return;
				}
		}
		else if(v!=parent[u])
		{
			low[u]=min(low[u],disc[v]);
		}
	}
}

void DFS1(int u, vector<bool>&visited, vector<vector<int>>&edges)
{
	visited[u]=true;
	
	for(auto v : edges[u])
	{
		if(!visited[v])
			DFS1(v,visited,edges);
	}
}
bool connected(int V, vector<vector<int>>&edges)
{
	vector<bool>visited(V,false);
	
	DFS1(0,visited,edges);
	
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
			return false;
	}
	
	return true;
}
bool twoEdgeConnectedGraph(vector<vector<int>> edges) {
  // Write your code here.
	int V=edges.size();
	
	if(V==1 || V==0)
		return true;
	
	bool s=false;
	
	for(auto v : edges)
	{
		if(v.size()>0)
			s=true;
	}
	
	if(s==false)
		return false;
	
	if(!connected(V,edges))
		return false;
	
	vector<int>parent(V,-1);
	vector<int>disc(V,-1);
	vector<int>low(V,-1);
	
	bool bridges=false;
	
	for(int i=0;i<V;i++)
	{
		if(disc[i]==-1)
		{
			DFS(i,parent,low,disc,edges,bridges);
			if(bridges)
				return false;
		}
	}
  return true;
}

int main()
{

}

//Tow edges graph == graph having 0 edges