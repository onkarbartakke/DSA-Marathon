#include <bits/stdc++.h>
#define ll long long
using namespace std;

int FormMixture(vector<int> &a, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    vector<int> prefix(n);

    prefix[0] = a[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    for (int win = 2; win <= n; win++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + win - 1;

            if (j >= n)
                break;

            if (win == 2)
            {
                dp[i][j] = (a[i] * a[j]);
            }
            else
            {
                int temp, currPartiton = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    int val1, val2;

                    if (i - 1 >= 0)
                        val1 = (prefix[k] - prefix[i - 1]) % 100;
                    else
                        val1 = prefix[k] % 100;

                    val2 = (prefix[j] - prefix[k]) % 100;

                    temp = (val1 * val2) + dp[i][k] + dp[k + 1][j];

                    currPartiton = min(currPartiton, temp);
                }

                dp[i][j] = currPartiton;
            }
        }
    }

    return dp[0][n - 1];
}
int main()
{

    int n;

    while (scanf("%d", &n) != EOF)
    {
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << FormMixture(a, n);
        cout << "\n";
    }
}