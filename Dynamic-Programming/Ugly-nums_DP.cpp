#include <iostream>

using namespace std;

ull getNthUglyNo(int n)
{
    // code here

    int i, j, k;
    int c1 = 0, c2 = 0, c3 = 0;

    ull dp[n + 1];
    dp[0] = 1;

    for (i = 1; i < n; i++)
    {
        dp[i] = min(2 * dp[c1], min(3 * dp[c2], 5 * dp[c3]));

        if (dp[i] == 2 * dp[c1])
            c1++;
        if (dp[i] == 3 * dp[c2])
            c2++;
        if (dp[i] == 5 * dp[c3])
            c3++;
    }

    return dp[n - 1];
}

int main()
{
    cout << "Enter the n for nth ugly num : ";
    int n;
    cin >> n;

    cout << "nth Ugly num is : " << getNthUglyNo(n);
}