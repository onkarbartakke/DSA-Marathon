#include<bits/stdc++.h>

using namespace std;

int dp[100][100];


int solve(int a[], int i, int j)
{
    if(i==j)
    return dp[i][i]=a[i];

    if(i>j)
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];


    int l=a[i]+min(solve(a,i+2,j),solve(a,i+1,j-1));
    int r=a[j]+min(solve(a,i+1,j-1),solve(a,i,j-2));

    return dp[i][j]=max(l,r);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,i,j;
    cout<<"Enter the num of coins : ";
    cin>>n;
    int a[n];

    cout<<solve(a,0,n-1);
}