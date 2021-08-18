#include <iostream>

using namespace std;

int main()
{
    int n, i, j, W;

    cout << "Enter the Num of Elements : ";
    cin >> n;

    int val[n], wt[n];

    cout << "Enter value and weight of n items : \n";
    for (i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }

    int dp[W + 1] = {0};

    for (j = 0; j <= W; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (j - wt[i] >= 0)
            {
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
            }
        }
    }

    cout << dp[W];
}