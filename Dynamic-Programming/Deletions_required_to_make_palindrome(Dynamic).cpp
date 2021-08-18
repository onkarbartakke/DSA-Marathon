#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int lps(string s)
{
	int i,j,len;
	int l=s.length();
	int dp[l][l];
	for(i=0;i<l;i++)
	{
		dp[i][i]=1;    //palindrome of length=1, starting and ending at i==similar to base case1 of recursion approach
	}
	
	for(len=2;len<=l;len++)
	{
		for(i=0;i<=l-len;i++)
		{
			j=i+len-1;
			if(s[i]==s[j] && len==2)  //palindrome of lenghth=2, == similar to base case 2 of recursion approach
			{
				dp[i][j]=2;
			}
			else if(s[i]==s[j])
			{
				dp[i][j]=2+dp[i+1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	
	return dp[0][l-1];
}

 
int main()
{

	
	
	cout<<"Enter the string\n";
	string s;
	cin>>s;
	int l=s.length();
	int ans=lps(s);    //longest palindromic subsequence
	cout<<l-ans;
	cout<<"\n";
	
}