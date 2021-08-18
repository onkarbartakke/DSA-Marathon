#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include<unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

bool charCheck(string s, unordered_map< char, vector<pair<int,int>> >&mp, vector<vector<bool>>&visited, int pos, int x, int y)
{
	if(pos>=s.length())
		return true;
	
	vector<pair<int,int>>v=mp[s[pos]];
	
	for(int i=0;i<v.size();i++)
	{
		int x1,y1;
		x1=v[i].first;
		y1=v[i].second;
		
		if(abs(x-x1)<=1 && abs(y-y1)<=1 && !visited[x1][y1])
		{
			visited[x1][y1]=true;
			if(charCheck(s,mp,visited,pos+1,x1,y1))
				return true;
			
			visited[x1][y1]=false;
		}
	}
	
	return false;
}

bool present(string s, unordered_map< char , vector<pair<int,int>> >&mp, vector<vector<char>>&board)
{
		int n,m,i,j;
	n=board.size();
	m=board[0].size();
	
	vector<vector<bool>>visited(n,vector<bool>(m,false));
	
	
	vector< pair<int,int>>v=mp[s[0]];
	for(i=0;i<v.size();i++)
	{
		int x,y;
		x=v[i].first;
		y=v[i].second;
		
		visited[x][y]=true;
		
		if(charCheck(s,mp,visited,1,x,y))
			return true;
		
		visited[x][y]=false;
	}
	
	return false;
	 
}

vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
  // Write your code here.
	unordered_map< char , vector<pair<int,int>> >mp;
	int n,m,i,j;
	n=board.size();
	m=board[0].size();
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			mp[board[i][j]].push_back({i,j});
		}
	}
	
	vector<string>ans;
	
	for(i=0;i<words.size();i++)
	{
		if(present(words[i],mp,board))
			 ans.push_back(words[i]);
	}
			 
  return ans;
}

int main()
{
    
}