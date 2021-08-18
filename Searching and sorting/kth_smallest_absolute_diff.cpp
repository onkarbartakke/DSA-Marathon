#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
int count_pairs(int a[],int n,int mid)
{
    int i,j,count=0;
    
    i=0;
    j=i+1;
    while(j<n)
    {
        while(a[j]-a[i]<=mid)
        {
            count++;
            j++;
        }
        
        while(i<j)
        {
            if(a[j]-a[i]<=mid)
            count++;
            
            i++;
        }
        if(i!=n-1)
        {
            j=i+1;
        }
        else
        break;
        while(a[j]-a[i]>mid && j<n)
        {
            i++;
            j++;
        }
    }
    
    return count;
}


*/


int count_pairs(int *a, int n, int mid) 
{ 
    int res = 0; 
    for (int i = 0; i < n; ++i) 
  
        // Upper bound returns pointer to position 
        // of next higher number than a[i]+mid in 
        // a[i..n-1]. We subtract (a + i + 1) from 
        // this position to count 
        res += upper_bound(a+i, a+n, a[i] + mid) - 
                                    (a + i + 1); 
    return res; 
} 


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
	    cin>>k;
	    sort(a,a+n);
	    int low,high,mid;
	    high=a[n-1]-a[0];
	    i=1;
	    low=a[1]-a[0];
	    while(i<n)
	    {
	        low=min(low, abs(a[i]-a[i-1]));
	        i++;
	    }
	    
	    
	    while(low<high)
	    {
	        mid=(low+high)/2;
	        if(count_pairs(a,n,mid)<k)
	        {
	            low=mid+1;
	        }
	        else
	        {
	            high=mid;
	        }
	        
	    }
	    
	    cout<<low<<"\n";
	}
	return 0;
}