#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, K;

    cin >> n >> m >> K;

    vector<long long int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int dp[n + 1][m + 1][K + 1];

    memset(dp, 0, sizeof dp);

    for (int k = 0; k <= K; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j][k] = 0;
                else
                {
                    if (a[i - 1] == b[j - 1])
                        dp[i][j][k] = dp[i - 1][j - 1][k] + 1;

                    if (a[i - 1] != b[j - 1])
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);

                    if (k > 0)
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - 1][k - 1]);
                }
            }
        }
    }

    cout << dp[n][m][K];
}