#include <iostream>
using namespace std;

int min_coin_change(int coin[],int v,int n)
{
    long int i,j,I;
    I=100001;
    if(v==0)
    {
        return 0;
    }
    if(n==0 && v>0)
    {
        return I;
    }
    int **dp;
    dp=new int*[n+1];
    for(i=0;i<n+1;i++)
    {
        dp[i]=new int[v+1];
    }
    
    for(i=0;i<v+1;i++)
    {
        dp[0][i]=I;
    }
    for(i=1;i<n+1;i++)
    {
        dp[i][0]=0;
    }
    
    
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<v+1;j++)
        {
            if(j<coin[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }
        }
    }
    
    if(dp[n][v]>=I)
    return -1;
    
    else
    return dp[n][v];
}
int main() {
	cout<<"Enter thr value v\n";
	int v,n,i;
	cin>>v;
	cout<<"Enter num of coins\n";
	cin>>n;
	int a[n];
	cout<<"Enter the denominations of coin\n";
	
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	int ans=min_coin_change(a,v,n);
	return 0;
}