#include <bits/stdc++.h>

using namespace std;
/*
Given N eggs and K floors

You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break,
 and any egg dropped at or below floor f will not break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

*/

int solve(int n, int k, vector<vector<int>> &dp)
{

    if (n == 1)  // If we have 1 egg left we need to it wisely and check all remaining K floors from bottom
        return dp[n][k] = k; // In worst case critical floor can be topmost floor hence K

    if (k == 1 || k == 0) // If 0 or 1 floor left ans is straightfloor attempt and check
        return dp[n][k] = k;

    if (dp[n][k] != -1)
        return dp[n][k];

    int caseAns, ans = INT_MAX;

    for (int f = 1; f <= k; f++) // In 1 . . . K floors check or choose the partition floor (All possible partitions)
    {
        caseAns = 1 + max(solve(n - 1, f - 1, dp), solve(n, k - f, dp)); // 1 attempt so +1 and choose max of the outcome(Worst case)
                            // Egg breaks so go downs    Egg doesnt break so go up
        ans = min(ans, caseAns); // Of all partitions choose the 1 with min attempts in worst case
    }

    return dp[n][k] = ans;
}


int eggDrop(int n, int k)
{
    // your code here

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    return solve(n, k, dp);
}


int main()
{
}