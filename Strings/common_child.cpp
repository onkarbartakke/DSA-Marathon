#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int dp[5001][5001];
//The crux of this problles is that when u define the dp 2d array inside the function, it fails for few cases, but when declared global
//it passes this beciz - Instead of defining 2d matrix inside a function, define it globally.
// In this way it will acquire data segment instead of stack memory.
int commonChild(string s1, string s2)
{
    int i,j,n,m;
    n=s1.length();
    m=s2.length();
    
    //int dp[n+1][m+1];
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }    
    
    return dp[n][m];
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;

    int count = commonChild(s1,s2);

    cout<<"\n\n*****\n\n"<<count;
}