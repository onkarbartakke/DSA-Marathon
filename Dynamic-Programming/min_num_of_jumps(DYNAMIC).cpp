#include <bits/stdc++.h>
using namespace std;


int hopper(int a[],int n)
{
    int *jump;
    int i,j;
    jump=new int [n];
    jump[0]=0;
    if(n==0 || a[0]==0)
    {
        return INT_MAX;
    }
    
    for(i=1;i<n;i++)
    {
        jump[i]=INT_MAX;
        for(j=0;j<i;j++)
        {
            if(i<=j+a[j] && jump[j]!=INT_MAX)
            {
                jump[i]=min(jump[j]+1,jump[i]);
                break;
            }
        }
    }
    
    return jump[n-1];
}
int main() {
    int n,i;
    cout<<"Enter num of towers\n";
    cin>>n;
    cout<<"Enter theheight of towers\n";
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int x=hopper(a,n);
    cout<<x;
	return 0;
}