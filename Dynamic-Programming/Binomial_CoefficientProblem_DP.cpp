#include<iostream>

using namespace std;

int nCk(int n, int k)
{
    if(n<k)
    return 0;

    if(n==k)
    return 1;
    
    int i,j;
    int dp[n+1][k+1];

    for(i=1;i<=n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            if(j==0 || j==i)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
            }
        }
    }


    return dp[n][k];
}


int main()
{
    int n,i,j,k;
    cout<<"Calculating nCk (C[n][k]) \n";
    cout<<"Enter the val if N : ";
    cin>>n;
    cout<<"Enter the val of K : ";
    cin>>k;

    cout<<"Val of nCk is "<<nCk(n,k);
}