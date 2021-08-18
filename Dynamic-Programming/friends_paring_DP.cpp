#include <iostream>

using namespace std;

int main()
{
    int n;

    if (n == 1 || n == 2)
    {
        cout << n;
    }
    else
    {
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }

        cout << dp[n];
    }
}