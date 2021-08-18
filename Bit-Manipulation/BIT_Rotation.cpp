#include <bits/stdc++.h>

#define INT_BITS  16
using namespace std;
int leftrotate(int n,int d)
{
    int l,r;
    l=n<<d;
    r=n>>(INT_BITS-d);
    
    return (l|r);
}


int rightrotate( int n, int d)
{
    int l,r;
    l=n>>d;
    
    r=n<<(INT_BITS-d);
    
    return (l|r);
    
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,d;
	    cin>>n>>d;
	
	    cout<<leftrotate(n,d);
	    cout<<"\n";
	    cout<<rightrotate(n,d);
	    cout<<"\n";
	}
	return 0;
}
