#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int  count=0;
void merge(int a[],int l,int m,int h) 
{
	int i,j,k;

	i=l;
	k=0;
	j=m+1;

	int c[h-l+1]={0};
	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			
			
			for(int t=i;t<=m;t++)
			{
				cout<<a[t]<<","<<a[j]<<"  ";
				
				count++;
			}
			k++;
			j++;
		}
	}
	
	for(;i<=m;i++)
	{
		c[k]=a[i];
		k++;
	}
	for(;j<=h;j++)
	{
		c[k]=a[j];
		k++;
	}
	k=0;
	for(i=l;i<=h;i++)
	{
		a[i]=c[k];
		k++;
	}
	
}

void  mergesort(int a[],int l,int h)
{
	
	if(l<h)
	{
		int m;
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		
		merge(a,l,m,h);
		
	}
	
	
}
int main() 
{
	int n,i,l,h;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	l=0;
	h=n-1;
	cout<<"\n";
	mergesort(a,l,h);
		cout<<"\n";
	
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	
	cout<<"\n\n";
	cout<<count;
	return 0;
}
