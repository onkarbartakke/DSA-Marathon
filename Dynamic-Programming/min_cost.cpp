#include <bits/stdc++.h>

using namespace std;

int minCost(string x, string y, int costX, int costY)
{
    int n = x.length();
    int m = y.length();

    vector<vector<int>>dp(n+1, vector<int>(m + 1,0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j * costY;
                continue;
            }
            else if (j == 0)
            {
                dp[i][j] = i * costX;
                continue;
            }
            else if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + costX, dp[i][j - 1] + costY);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string x, y;
    int costx, costy;
    cout << "Enter the 1st str : \n";
    cin >> x;
    cout << "Enter the cost : ";
    cin >> costx;
    cout << "Enter the 2nd str : \n";
    cin >> y;
    cout << "Enter the cost : ";
    cin >> costy;

    cout << "\n\ncost is : " << minCost(x, y, costx, costy);
}