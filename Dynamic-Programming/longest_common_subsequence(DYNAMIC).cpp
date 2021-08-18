#include <iostream>
#include <string>
using namespace std;


int lcs(int x, int y, string s1, string s2)
{
    
    // your code here
    int **dp;
    int i,j;
    dp=new int*[x+1];
    
    for(i=0;i<x+1;i++)
    {
        dp[i]=new int[y+1];
    }
    
    for(i=0;i<=x;i++)
    {
        for(j=0;j<=y;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]==0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    return dp[x][y];
}
int main() {
	string s1,s2;
	int  x,y;
	//cin>>x>>y;
	cout<<"Enter the 1st string\n";
	cin>>s1;
	cout<<"Enter the 2nd string\n";
	cin>>s2;
	x=s1.length();
	y=s2.length();
	cout<<lcs(x,y,s1,s2);
	return 0;
}