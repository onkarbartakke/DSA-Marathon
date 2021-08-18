#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    int a[n],b[n];
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(i=0;i<n;i++)
	    {
	        cin>>b[i];
	    }
	    
	    sort(a,a+n);
	    sort(b,b+n);
	    int f=1;
	    for(i=0;i<n;i++)
	    {
	        if(a[i]>b[i])
	        {
	            f=0;
	            break;
	        }
	    }
	    
	    if(f==1)
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	}
	return 0;
}