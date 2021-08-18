#include<iostream>

using namespace std;

string LC_string(string s1,  string s2)
{
    int i,j,l1,l2;
    l1=s1.length();
    l2=s2.length();
    int dp[l1+1][l2+1];
    int max, x,y;
    max=0;
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }

            if(dp[i][j]>max)
            {
                max=dp[i][j];
                x=i-1;
                y=j-1;
            }
        }
    }
   
    int len=max;
    char ans[len+1];
    ans[len]='\0';
    len--;
    while(len>=0)
    {
       
        ans[len]=s1[x];
        len--;
        x--;
    }
 
    return ans;
}

int main()
{
    string s1,s2;
    cout<<"Enter the 1st String : ";
    cin>>s1;
    cout<<"Enter 2nd string : ";
    cin>>s2;

    string lcs=LC_string(s1,s2);
    cout<<"\nLongest common string is : "<<lcs;
}