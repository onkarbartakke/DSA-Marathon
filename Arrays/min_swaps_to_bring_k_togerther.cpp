#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,k,count=0;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cin>>k;
	    
	    for(i=0;i<n;i++)
	    {
	        if(a[i]<=k)
	        count++;
	    }
	    int ans=100;
	    for(i=0,j=count-1;j<n;i++,j++)
	    {
	        int s=i;
	        int swap=0;
	        while(s<=j)
	        {
	            if(a[s]>k)
	            swap++;
	            
	            s++;
	        }
	        
	        ans=min(ans,swap);
	    }
	    
	    cout<<ans<<"\n";
	}
	
	return 0;
}