#include<iostream>

using namespace std;
int min(int a,int b,int c)
{
    return (a<b)?((a<c)?a:c):((b<c)?b:c);
}
int cost(string s1, string s2)
{
    int i,j,l1,l2;
    l1=s1.length();
    l2=s2.length();

    int dp[l1+1][l2+1];

    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(i==0)
            dp[i][j]=j;
            else if(j==0)
            dp[i][j]=i;
            else 
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                {
                    int insert,del,replace;

                    insert=dp[i][j-1];
                    del=dp[i-1][j];
                    replace=dp[i-1][j-1];

                    dp[i][j]=1+min(insert,del,replace);
                }
            }
        }
    }

    return dp[l1][l2];
}

int main()
{
    string s1,s2;
    cout<<"Enter the 1st String : ";
    cin>>s1;
    cout<<"\nEnter the 2nd String : ";
    cin>>s2;
    

    int ans=cost(s1,s2);
    cout<<"\n\nConversion from S1 to S2 costs : "<<ans;
}