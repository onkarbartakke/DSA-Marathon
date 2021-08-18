#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool mycomp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first>p2.first;
}

int main() {
	int n,i;
	cin>>n;
	int cost[2*n][2];
	
	vector< pair<int,int> >v;
	
	for(i=0;i<2*n;i++)
	{
	    cin>>cost[i][0]>>cost[i][1];
	    
	    pair<int,int>p;
	    p.first=cost[i][1]-cost[i][0];
	    p.second=i;
		v.push_back(p);
	}
	
	sort(v.begin(),v.end(),mycomp);
	int sum=0;
	for(i=0;i<n;i++)
	{
	    sum=sum+cost[v[i].second][0];
	}
	for(;i<2*n;i++)
	{
	    sum=sum+cost[v[i].second][1];
	}
	cout<<sum;
	return 0;
}