#include<iostream>

using namespace std;

string LP_string(string s)
{
    int i,j,l,k;
    l=s.length();
    int dp[l][l];

    for(i=0;i<l;i++)
    {
        for(j=0;j<l;j++)
        {
            dp[i][j]=0;
        }
    }


    for(i=0;i<l;i++)
    {
        dp[i][i]=1;
    }


    int len=2;
    int length=0,x,y;
    for(len=2;len<=l;len++)
    {
        for(i=0;i<l-len+1;i++)
        {
            j=i+len-1;

            if(len==2 && s[i]==s[j])
            {
                dp[i][j]=2;
            }
            else if(s[i]==s[j] && dp[i+1][j-1]!=0)
            {
                dp[i][j]=j-i+1;
            }

            if(dp[i][j]>length)
            {
                length=dp[i][j];
                x=i;
                y=j;
            }
        }
    }
    cout<<"\n"<<length<<"\n";
    char lps[length+1];
    lps[length]='\0';
    k=0;
    for(i=x;i<=y;i++)
    {
        lps[k]=s[i];
        k++;
    }

    return lps;
}
int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    string ans=LP_string(s);
    cout<<"Longest Palindromic string :"<<ans;
}