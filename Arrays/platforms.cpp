#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int platforms(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
	sort(dep,dep+n);
	int i,j,needed,curr;
	needed=0;
	curr=0;
	
	i=0;j=0;
	while(i<n && j<n)
	{
	    if(arr[i]<=dep[j])
	    {
	        curr++;
	        needed=max(needed,curr);
	        i++;
	    }
	    else if(arr[i]>dep[j])
	    {
	        curr--;
	        j++;
	    }
	}
	
	return needed;
}

int main() {
	int n,i;
	cin>>n;
	int arr[n],dep[n];
	
	for(i=0;i<n;i++)
	{
	    cin>>arr[i]>>dep[i];
	}
	
	int p=platforms(arr,dep,n);
	cout<<p;
	return 0;
}