#include <iostream>
using namespace std;
/*int profit(int a[],int y,int left,int right)
{
    if(left==right)
    {
        return y*a[left];
    }
    else
    {
        return max(a[left]*y+profit(a,y+1,left+1,right),a[right]*y+profit(a,y+1,left,right-1));
    }
}
*/

int profit_in_range(int a[],int y,int left,int right,int **dp)
{
    if(dp[left][right]!=-1)
    {
        return dp[left][right];
    }
    
    if(left==right)
    {
        dp[left][left]=y*a[left];
        return dp[left][right];
    }
    else
    {
        dp[left][right]=max(a[left]*y+profit_in_range(a,y+1,left+1,right,dp),a[right]*y+profit_in_range(a,y+1,left,right-1,dp));
        return dp[left][right];
    }
}
int profit(int a[],int n)
{
    int **dp;
    dp=new int*[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        dp[i]=new int[n];
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int y,left,right;
    left=0;
    right=n-1;
    y=1;
    return profit_in_range(a,y,left,right,dp);
}
int main() {
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	int ans=profit(a,n);
	cout<<ans;
	return 0;
}