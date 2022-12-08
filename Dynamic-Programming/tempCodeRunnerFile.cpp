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