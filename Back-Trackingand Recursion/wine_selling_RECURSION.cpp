#include <iostream>
using namespace std;
int profit(int a[],int n,int y,int left,int right)
{
    if(left==right)
    {
        return y*a[left];
    }
    else
    {
        return max(a[left]*y+profit(a,n,y+1,left+1,right),a[right]*y+profit(a,n,y+1,left,right-1));
    }
}
int main() {
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	int ans=profit(a,n,1,0,n-1);
	cout<<ans;
	return 0;
}