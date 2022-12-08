#include<bits/stdc++.h>

using namespace std;


int solve(string s)
{
    int n = s.length();

    int dp[n+1][n+1];

    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // dp[i][j] is the count of palindromic subseq of length 3 in [i....j]


    for(int i = 0 ; i< n ; i++)
    dp[i][i] = 1;


    for(int win = 3 ; win <= n ; win++) // Counting Palindromic subsecquneces of Len 3
    {
        for(int i = 0 ; i < n ; i++)
        {
           int j = i + win - 1;
           
           if(j >= n)
           break;


           if(s[i] == s[j])
           {
                dp[i][j] = j - i - 1;
           }

        }
    }

    for(int win = 5 ; win<=n ; win++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            int j = i + win -1;

            if(j >= n)
            break;

            if(s[i] == s[j])
            {
                dp[i][j] += dp[i+1][j-1];
            }
        }
    }

    return dp[0][n-1];
}


int main()
{
    string s;
    cin>>s;
    solve(s);
}