#include<iostream>

using namespace std;

int Burst(int a[], int n)
{
    int dp[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]=0;
        }
    }

    int win,left,right,N;
    N=n-2;
    for(win=1;win<=N;win++)
    {
        for(left=1;left<=N-win+1;left++)
        {
            right=left+win-1;

            for(i=left;i<=right;i++)
            {
                dp[left][right]=max(dp[left][right], ( (a[left-1]*a[i]*a[right+1]) + dp[left][i-1] + dp[i+1][right] ) ) ;
            }
        }
    }

    return dp[1][n-2];
}

int main()
{
    int n,i;
    cout<<"Enter the Bursting Window size(no. of elements) : ";
    cin>>n;
    n=n+2;
    int a[n];
    a[0]=1;
    a[n-1]=1;
    cout<<"\n\nEnter the colours (nums) : ";
    for(i=1;i<=n-2;i++)
    {
        cin>>a[i];
    }

    int score=Burst(a,n);
    cout<<"\n\nMax Score is : "<<score;
}