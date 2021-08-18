#include <bits/stdc++.h>
#include <iostream>
using namespace std;


bool mycomp(pair<int,int>p1, pair<int,int>p2)
{
    if(p1.first==p2.first)
    {
        return p1.second>p2.second;
    }
    else
    {
        return p1.first<p2.first;
    }
}

int main() {
	int n,i;
	cin>>n;
	int a[n][2];
	vector< pair<int,int>>v;
	
	for(i=0;i<n;i++)
	{
	   cin>>a[i][0]>>a[i][1];
	   
	     pair<int,int>p1;
	     pair<int,int>p2;
	     
	     p1.first=a[i][0];
	     p1.second=1;
	     
	     p2.first=a[i][1];
	     p2.second=-1;
	     
	     v.push_back(p1);
	     v.push_back(p2);
	}
	
	sort(v.begin(),v.end(),mycomp);
	
	int len,max_len,count;
	len=0;
	count=0;
	max_len=0;
	
	for(i=0;i<2*n;i++)
	{
	    if(v[i].second==1)
	    {
	        if(count!=0)
	         len=len+v[i].first-v[i-1].first;
	         
	        count++;
	      
	    }
	    else if(v[i].second==-1)
	    {
	        count--;
	        len=len+v[i].first-v[i-1].first;
	        
	        if(count==0)
	        {
	            max_len=max(max_len,len);
	            len=0;
	        }
	    }
	}
	
	cout<<max_len;
	
	return 0;
}