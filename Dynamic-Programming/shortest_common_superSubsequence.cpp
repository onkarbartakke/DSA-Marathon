#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string LCS(string &X, string &Y)
    {
        int n = X.length(), m = Y.length();

        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = "";
                else if (X[i - 1] == Y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + X[i - 1];
                }
                else
                {
                    if (dp[i - 1][j].length() > dp[i][j - 1].length())
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }

    
    string shortestCommonSupersequence(string str1, string str2)
    {

        string lcs = LCS(str1, str2);

        string res = "";
        int i = 0, j = 0;
        for (auto c : lcs)
        {
            while (str1[i] != c)
                res += str1[i++];

            while (str2[j] != c)
                res += str2[j++];

            res += c;
            i++;
            j++;
        }

        res += (str1.substr(i) + str2.substr(j));

        return res;
    }
};