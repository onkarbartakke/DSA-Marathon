#include<iostream>
#include<vector>
#include<queue>

using namespace  std;

vector<int> sortKSortedArray(vector<int> array, int k) {
  // Write your code here.
	if(k==0)
		return array;
	priority_queue<int,vector<int>, greater<int> >pq;
	
	for(int i=0;i<k;i++)
	{
		pq.push(array[i]);
	}
	int n=array.size();
	for(int i=0;i<n;i++)
	{
		int j=i+k;
		if(j<n)
		{
			pq.push(array[j]);
		}
		array[i]=pq.top();
		pq.pop();
	}
  return array;
}

int main()
{

	    int i,n,k;
	    cin>>n>>k;
	    vector<int>array(n);
	    
	    for(i=0;i<n;i++)
	    cin>>array[i];
	    
	    vector<int>ans=sortKSortedArray(array,k);
	    
	    for(i=0;i<n;i++)
	    cout<<ans[i]<<" ";
	    
}
