#include <iostream>
#define size 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
long int trapped_water(int a[],int n)
{
	int i,j;
	int left[n],right[n];
	left[0]=a[0];

	
	for(i=1;i<n;i++)
	{
		left[i]=max(a[i],left[i-1]);
	}
	
	right[n-1]=a[n-1];

	for(i=n-2;i>=0;i--)
	{
		right[i]=max(a[i],right[i+1]);
	}
	long int water=0;
	for(i=0;i<n;i++)
	{
		water=water+ min(left[i],right[i])-a[i];
	}
	
	return water;
}
int main()
{
	int n,i;
	cout<<"Enter num of bars in arry\n";
	cin>>n;
	int a[size];
	cout<<"Enter the elements of array\n";
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	long int ans=trapped_water(a,n);
	
	cout<<ans;
}
