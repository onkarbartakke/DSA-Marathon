#include <iostream>
using namespace std;

long long int sum_bit_diff(long int a[],long int n)
{
      long long int i,j,count,ans;
	    count=0;
	    ans=0;
	    for(i=0;i<32;i++)
	    {
	        count=0;
	        for(j=0;j<n;j++)
	        {
	            if(a[j] & (1<<i))
	            count++;
	        }
	        
	        ans=ans+(count*(n-count)*2);
	    }
	    
	    return ans;
}

int main() {
	
	long int n,i;
	cin>>n;
	long int a[n];
	
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	cout<<sum_bit_diff(a,n);
	return 0;
}