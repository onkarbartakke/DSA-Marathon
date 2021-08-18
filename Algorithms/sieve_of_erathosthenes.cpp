#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	int a[n+1]={0};
	
	for(i=2;i<=n;i++)
	{
		if(a[i]==0)
		{
			for(j=i*i;j<=n;j=j+i)
			a[j]=1;
		}
	}
	
	int spf[n+1]; //smallest prime factor

	for(i=1;i<=n;i++)
	spf[i]=i;

	for(i=2;i<=n;i++)
	{
		if(spf[i]==i)
		{
			for(j=i*i;j<=n;j=j+i)
			{
				if(spf[j]==j)
				spf[j]=i;
			}
		}
	}
	
	for(i=2;i<=n;i++)
	{
		if(a[i]==0)
		cout<<i<<" ";
	}
}
