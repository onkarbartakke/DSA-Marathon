#include <iostream>
using namespace std;

int main() {
	cout<<"Enter the num of elements\n";
	int n,i,q;
	cin>>n;
	cout<<"Enter the n elements\n";
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	int LR[2][q];
	for(i=0;i<q;i++)
	{
	    cin>>LR[0][i]>>LR[1][i];
	}
	
	int xoor[n];
	xoor[0]=a[0];
	for(i=1;i<n;i++)
	{
	    xoor[i]=xoor[i-1]^a[i];
	}
	
	for(i=0;i<q;i++)
	{
	    if(LR[0][i]==0)
	    {
	        cout<<xoor[LR[1][i]];
	    }
	    else
	    {
	        cout<<xoor[LR[1][i]]^xoor[LR[0][i]-1]
	    }
	}
	return 0;
}