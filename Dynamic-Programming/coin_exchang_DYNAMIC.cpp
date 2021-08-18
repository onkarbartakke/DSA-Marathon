#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
long int exchange(long int a[],long int m,long int n)
{
	int dp[n+1][m];
	long int i,j,x,y;
	
	for(i=0;i<m;i++)
	{
		dp[0][i]=1;  //similary to base case 1, of recursive
					//solution , where amount, n=0 so only 1 way
	}
	
	for(i=1;i<n+1;i++)
	{
		for(j=0;j<m;j++)
		{
			//considering the jth denomination coin for amount i
			x=(i-a[j]>=0)? dp[i-a[j]][j]:0;
			//not considering the jth denomination coin for amount i
			y=(j>=1)? dp[i][j-1]:0;
			
			dp[i][j]=x+y;
		}
	}
	
	return dp[n][m-1];
}

int main()
{
	long int n,i,m;
	cout<<"Enter the amount u want to exchange\n";
	cin>>n;
	cout<<"Enter the number of denominations\n";
	cin>>m;
	long int a[m];
	cout<<"Enter the denominations(values) of coins\n";
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	long int ans=exchange(a,m,n);
	cout<<ans;
	cout<<"\n";
}
