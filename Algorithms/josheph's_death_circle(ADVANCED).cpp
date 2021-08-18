#include <iostream>
using namespace std;
int win(int n,int k)
{
    if(n==1)
    return 1;
    else
    {
        return (win(n-1,k)+k-1)%n+1;
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int ans=win(n,k);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}
