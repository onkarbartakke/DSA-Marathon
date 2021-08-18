#include <iostream>
using namespace std;

bool max_page(int mid, int m, int n,int p[])
{
        int i,student,book=0;
        student=1;
        for(i=0;i<n;i++)
        {
            if(book+p[i]>mid)
            {
                student++;
                book=p[i];
                if(student>m)
                return false;
            }
            else
            {
                book+=p[i];
            }
        }
        
        
        return true;
}

int main() {
	int n,m,i;
	cin>>n;
	int p[n];
	int high,low,mid;
	high=0;
	low=p[0];
	for(i=0;i<n;i++)
	{
	    cin>>p[i];
	    high+=p[i];
	}
	int ans=low;
	while(low<high)
	{
	    mid=(low+high)/2;
	    
	    if(max_page(mid,m,n,p))
	    {
	        ans=mid;
	        high=mid-1;
	    }
	    else
	    {
	        low=mid+1;
	    }
	}
	
	cout<<ans;
	
	return 0;
}