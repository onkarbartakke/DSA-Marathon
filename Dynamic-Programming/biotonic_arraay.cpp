#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j;
	    cin>>n;
	    int a[n];
	    int a1[n]={0};
	    int a2[n]={0};
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        a1[i]=a[i];
	        a2[i]=a[i];
	    }
	    
	    for(i=0;i<n-1;i++)
	    {
	        int m=a[i];
	        for(j=i+1;j<n;j++)
	        {
	            if(a[j]<m)
	            {
	                a1[i]=a1[i]+a[j];
	                m=a[j];
	            }
	        }
	    }
	    
	    cout<<"\n \n";
	    
	     for(i=0;i<n;i++)
	     {
	     	cout<<a1[i]<<" ";
		 }
		 cout<<"\n \n";
		 
		 
	    
	    for(i=n-1;i>0;i--)
	    {
	        int m=a[i];
	        for(j=i-1;j>=0;j--)
	        {
	            if(a[j]<m)
	            {
	                a2[i]=a2[i]+a[j];
	                m=a[j];
	            }
	        }
	    }
	    
	    for(i=0;i<n;i++)
	     {
	     	cout<<a2[i]<<" ";
		 }
		 cout<<"\n \n";
	    
	    for(i=0;i<n;i++)
	    {
	        a[i]=a1[i]+a2[i]-a[i];
	    }
	    int max=a[0];
	    for(i=0;i<n;i++)
	    {
	    	cout<<a[i]<<" ";
	        if(a[i]>max)
	        max=a[i];
	    }
	    
	    cout<<"\n"<<max<<"\n";
	}
	return 0;
}
