#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long

using namespace std;

/*
Given three integers x, y, and z, the task is to find the sum of all the numbers formed by 
having 4 at most x times, having 5 at most y times, and having 6 at most z times as a digit.

Note: Output the sum modulo 109+7.
*/
int getSum(int X, int Y, int Z)
{
    // Your code goes here

    ll exactSum[61][61][61] = {0};
    ll exactNum[61][61][61] = {0};

    ll ans = 0;

    exactNum[0][0][0] = 1;
    for (int i = 0; i <= X; i++)
    {
        for (int j = 0; j <= Y; j++)
        {
            for (int k = 0; k <= Z; k++)
            {
                if (i > 0)
                {
                    exactSum[i][j][k] += ((exactSum[i - 1][j][k] * 10) % mod + 4 * (exactNum[i - 1][j][k]) % mod) % mod;
                    exactNum[i][j][k] += exactNum[i - 1][j][k] % mod;
                }

                if (j > 0)
                {
                    exactSum[i][j][k] += ((exactSum[i][j - 1][k] * 10) % mod + 5 * (exactNum[i][j - 1][k]) % mod) % mod;
                    exactNum[i][j][k] += exactNum[i][j - 1][k] % mod;
                }

                if (k > 0)
                {
                    exactSum[i][j][k] += ((exactSum[i][j][k - 1] * 10) % mod + 6 * (exactNum[i][j][k - 1]) % mod) % mod;
                    exactNum[i][j][k] += exactNum[i][j][k - 1] % mod;
                }

                ans += (exactSum[i][j][k] % mod);
                ans = (ans % mod);
            }
        }
    }

    return (int)ans;
}