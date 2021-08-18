#include <iostream>
#define inf 10000
using namespace std;


int count(int a[], int l,int h, int x)
{
    if(x==0)
    return 0;
    
    if(l==h && x==a[l])
    {
        return 1;
    }
    else if(l==h && x>a[l])
    {
        return inf;
    }
    
    if(l<h)
    {
        if(a[l]>x && a[h]<=x)
        {
        return 1+count(a,l,h-1,x-a[h]);
        }
        else if(a[l]<=h && a[h]>x)
        {
            return 1+count(a,l+1,h,x-a[l]);
        }
        else if(a[l]>x && a[h]>x)
        {
            return inf;
        }
        else if(a[l]<=h && a[h]<=x)
        {
            return 1+min(count(a,l+1,h,x-a[l]),count(a,l,h-1,x-a[h]));
        }
    }
}

int main() {
	int n,x,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	cin>>x;
	int s=count(a,0,n-1,x);
	if(s>=inf)
	cout<<-1;
	else
	cout<<s;
	return 0;
}