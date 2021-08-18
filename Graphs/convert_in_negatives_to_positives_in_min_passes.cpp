#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
  // Write your code here.
	
	int i,j,m,n;
	n=matrix.size();
	m=matrix[0].size();
	
	int passes=0;
	
	queue<pair<int,int>>qu;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matrix[i][j]>0)
			{
				qu.push({i,j});
			}
		}
	}
	
	while(!qu.empty())
	{
		int size=qu.size();
		while(size--)
		{
			pair<int,int>p=qu.front();
			qu.pop();
			int x,y;
			x=p.first;
			y=p.second;
			
			if(x+1<n && matrix[x+1][y]<0)
			{
				matrix[x+1][y]*=(-1);
				qu.push({x+1,y});
			}
			
			if(x-1>=0 && matrix[x-1][y]<0)
			{
				matrix[x-1][y]*=(-1);
				qu.push({x-1,y});
			}
			
			if(y+1<m && matrix[x][y+1]<0)
			{
				matrix[x][y+1]*=(-1);
				qu.push({x,y+1});
			}
			
			if(y-1>=0 && matrix[x][y-1]<0)
			{
				matrix[x][y-1]*=(-1);
				qu.push({x,y-1});
			}
		}
		
		passes++;
		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matrix[i][j]<0)
				return -1;
		}
	}
	
	return passes-1;
}

