#include <vector>
#include <unordered_map>
#include<string>
#include<climits>
using namespace std;

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
  // Write your code here;
	int n,i,j,r,b;
	r=reqs.size();
	b=blocks.size();
	
	unordered_map<string,vector<int> >dist;
	
	for(i=0;i<r;i++)
	{
		string curr=reqs[i];
		
		vector<int>left(b,INT_MAX);
		vector<int>right(b,INT_MAX);
		
		unordered_map<string,bool>mp;
		mp=blocks[0];
		
		if(mp[curr]==true)
			left[0]=0;
		
		for(j=1;j<b;j++)
		{
			mp=blocks[j];
			
			if(mp[curr])
				left[j]=0;
			else if(left[j-1]!=INT_MAX)
			{
				left[j]=left[j-1]+1;
			}
		}
		
		
		mp=blocks[b-1];
		if(mp[curr])
			right[b-1]=0;
		
		for(j=b-2;j>=0;j--)
		{
			mp=blocks[j];
			if(mp[curr])
				right[j]=0;
			else if(right[j+1]!=INT_MAX)
			{
				right[j]=right[j+1]+1;
			}
		}
		
		vector<int>v(b);
		for(j=0;j<b;j++)
		{
			v[j]=(min(left[j],right[j]));
		}
		
		dist[curr]=v;
	}
	int m=0,d;
	vector<int>ans(b);
	for(i=0;i<b;i++)
	{
		m=0;
		for(j=0;j<r;j++)
		{
			string curr=reqs[j];
			vector<int>v=dist[curr];
			
			if(v[i] > m)
			{
				m=v[i];
			}
		}
		
		ans[i]=m;
	}
	int idx;
	d=INT_MAX;
	for(i=0;i<b;i++)
	{
		if(ans[i]<d)
		{
			idx=i;
			d=ans[i];
		}
	}
  return idx;
}

int main()
{
    
}