#include<iostream>

using namespace std;

const int MOD=1e9+7;

int Pow(int a, int n)
{
    a=a%MOD;
    int ans=1;

    while(n>0)
    { 
       if(n&1)
       ans=(ans*a)%MOD;


       a=(a*a)%MOD;

       n=n>>1;
    }

    return ans;
}
int main()
{
    cout<<"Enter 'a' and 'n' to cal pow(a,n) : ";
    int a,n;
    cin>>a>>n;

    cout<<"\npow(a,n) : "<<Pow(a,n);
}