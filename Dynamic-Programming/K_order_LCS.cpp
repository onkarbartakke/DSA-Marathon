
#include <bits/stdc++.h>

using namespace std;

int K_LCS(string s1, string s2, int K)
{
    int i, j, k, l1, l2;
    l1 = s1.length();
    l2 = s2.length();

    int dp[l1 + 1][l2 + 1][k + 1];

    memset(dp, -1, sizeof(dp));

    for (k = 0; k <= K; k++)
    {
        for (i = 0; i <= l1; i++)
        {
            for (j = 0; j <= l2; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j][k] = 0;
                }
                else
                {
                    int c1 = -1, c2 = -1, c3 = -1;

                    if (s1[i - 1] == s2[j - 1])
                    {
                        c1 = 1 + dp[i - 1][j - 1][k];
                    }

                    if (k > 0)
                    {
                        c2 = 1 + dp[i - 1][j - 1][k - 1];
                    }

                    c3 = max(dp[i][j - 1][k], dp[i - 1][j][k]);

                    dp[i][j][k] = max(c1, max(c2, c3));
                }
            }
        }
    }

    return dp[l1][l2][K];
}

int main()
{
    string s1, s2;
    cout << "Enter the 1st string : ";
    cin >> s1;

    cout << "Enter the 2nd string : ";
    cin >> s2;

    cout << "Entr the K : ";
    int k;
    cin >> k;

    cout << "K-Order LCS is : " << K_LCS(s1, s2, k);
}