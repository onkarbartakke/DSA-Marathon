#include<iostream>
#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  // Write your code here.
	vector<vector<int>>ret;
	
	int n,i,j;
	n=array.size();
	if(n==0)
	{
		ret.push_back({0});
		ret.push_back({});
	}
	vector<int>sum(n);
	
	for(i=0;i<n;i++)
		sum[i]=array[i];
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(array[j] < array[i])
				sum[i]=max(sum[i],sum[j]+array[i]);
		}
	}
	
	int s=INT_MIN;
	int idx;
	int sub;
	for(i=0;i<n;i++)
	{
		if(sum[i]>s)
		{
			s=sum[i];
			idx=i;
		}
	}
	
	sub=s;
	vector<int>ans;

	while(idx>=0)
	{
		ans.push_back(array[idx]);
		s=s-array[idx];
		
		i=idx;
		while(i>=0)
		{
			if(s==sum[i])
			{
				idx=i;
				break;
			}
			
			i--;
		}
		
		if(i<0)
			break;
	}
	
//	vector<vector<int>>ret;
	ret.push_back({sub});
	sort(ans.begin(),ans.end());
	ret.push_back(ans);
	
	return ret;
     
}
