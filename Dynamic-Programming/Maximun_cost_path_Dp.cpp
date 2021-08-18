
#include<bits/stdc++.h>

using namespace std;

int max(int a=0,int b=0, int c=0)
{
    return (a>b)?((a>c)?a:c):((b>c)?b:c);
}



int maximumPath(int N, vector<vector<int>> Matrix)
{
        // code here
    int i,j,path,m;
    int dp[N][N];
    for(i=0;i<N;i++)
    {
        dp[0][i]=Matrix[0][i];
    }
                
    for(i=1;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(j==0)
            {
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j], dp[i-1][j+1]);
            }
            else if(j==N-1)
            {
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j], dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]);
            }
        }
    }
        path=0;
                
        for(i=0;i<N;i++)
        {
            path=max(path,dp[N-1][i]);
        }
                
        return path;
}
int main()
{
    int n,i,j;
    cout<<"Enter the Size of Matrix : ";
    cin>>n;
    vector<vector<int>> mat(n, vector<int>(n,0));
   
    cout<<"Enter the Costs of blocks : ";
    cout<<"\n\n";

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }

    int ans=maximumPath(n,mat);
    cout<<"\n"<<ans;

}