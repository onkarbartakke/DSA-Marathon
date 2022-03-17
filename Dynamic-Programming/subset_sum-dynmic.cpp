#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int sum_subset(int a[],int n, int s)
{
	int dp[n+1][s+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	
	for(i=1;i<=s;i++)
	{
		dp[0][i]=0;
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=s;j++)
		{
			if(j<a[i-1])
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];	
			}	
		}	
	}	
	return dp[n][s];
}

int main()
{
	int n,i,s;
	cout<<"Enter the number of elemensts\n";
	cin>>n;
	cout<<"Enter the n elements\n";
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the sum\n";
	cin>>s;
	int ans=sum_subset(a,n,s);
	
	cout<<ans;
}