#include <iostream>
using namespace std;

int findmajority(int a[],int n)
{
    int count=1;
    int maj_index=0;
    int i;
    for(i=1;i<n;i++)
    {
        if(a[maj_index]==a[i])
        count++;
        else
        count--;
        
        if(count==0)
        {
        maj_index=i;
        count=1;
        }
    }
    
    return a[maj_index];
}


bool ismaj(int a[],int n,int x)
{
    int count,i;
    count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        count++;
    }
    
    if(count>n/2)
    return 1;
    else
    return 0;
}

int main() {
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	int x=findmajority(a,n);
	
	
	if(ismaj(a,n,x))
	cout<<x<<" is majority element\n";
	else
	cout<<"no majority element\n";
	return 0;
}