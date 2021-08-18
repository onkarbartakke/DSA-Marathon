#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    srand(time(0));
	int n,i;
	cin>>n;
	
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	int cumlsum[n];
	cumlsum[0]=a[0];
	for(i=1;i<n;i++)
	{
	    cumlsum[i]=cumlsum[i-1]+a[i];
	}
	
	int wt=rand()%(cumlsum[n-1]);
	
	int index=upper_bound(cumlsum,cumlsum+n,wt)-cumlsum;
	cout<<index;
	return 0;
}
