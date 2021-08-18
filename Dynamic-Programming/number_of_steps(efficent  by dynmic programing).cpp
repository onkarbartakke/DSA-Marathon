#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int steps(int n,int a[],int x)
{
	if(n==0)
	return 1;
	else
	{
		int num_of_ways[n+1];
		num_of_ways[0]=1;
		int i,j;
		for(i=1;i<=n;i++)
		{
			int total=0;
			for(j=0;j<x;j++)
			{
				if(i-a[j]>=0)
				total=total+num_of_ways[i-a[j]];
			}
			num_of_ways[i]=total;
		}
		
		return num_of_ways[n];
	}
}
int main()
{
	int n,i;
	cout<<"Enter num of steps in staircase\n";
	cin>>n;
	cout<<"Enter num of steps which are allowed\n";
	int x;
	cin>>x;
	cout<<"Enter the value of steps\n";
	int a[x];
	for(i=0;i<x;i++)
	{
		cin>>a[i];
	}
	int ans=steps(n,a,x);
	
	cout<<ans;
}
