#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,k;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    int great[n];
	    int small[n];
	    great[0]=a[0];
	    small[n-1]=a[n-1];
	    k=0;
	    for(i=1;i<n;i++)
	    {
	        great[i]=max(great[i-1],a[i]);
	    }
	    for(i=n-2;i>=0;i--)
	    {
	        small[i]=min(small[i+1],a[i]);
	    }
	    
	    for(i=1;i<n-1;i++)
	    {
	        if(small[i]==great[i])
	        {
	            k=1;
	            cout<<small[i];
	            break;
	        }
	    }
	    if(k==0)
	    cout<<"-1";
	    
	    cout<<"\n";
	}
	return 0;
}
