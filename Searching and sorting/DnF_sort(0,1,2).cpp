#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int n,i,j;
	cout<<"Enter the num of elements in array\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements 0,1,2\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l,h,m;
	l=0;
	m=0;
	h=n-1;
	while(m<h)
	{
		if(a[m]==1)
		{
			m++;
		}
		else if(a[m]==0)
		{
			j=a[m];
			a[m]=a[l];
			a[l]=j;
			m++;
			l++;
		}
		else if(a[m]==2)
		{
			j=a[m];
			a[m]=a[h];
			a[h]=j;
			h--;
		}
	}
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
