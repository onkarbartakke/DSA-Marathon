#include <bits/stdc++.h>

using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    i=0;
	    int count=1;
	    int left=n;
	    while(i<n-1)
	    {
	        
	        while(a[i]==a[i+1] && i<n-1)
	        {
	            count++;
	            i++;
	        }
	       
	        if(i!=n-1)
	        {
	        left=left-count;
	        count=1;
	        cout<<left<<" ";
	           i++;
	        }    
	        
	    }
	    
	    cout<<"\n";
	}
	return 0;
}