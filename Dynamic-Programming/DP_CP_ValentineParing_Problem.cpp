#include <bits/stdc++.h>

using namespace std;
/*
Given N bois and M girls where M >= N
each of N bois have some chocolates with them mentioned in the array of size N, where ith boy has arr[i] chocolates
each of M girls have some candies with them mentioned in the array of size M, where ith girl has arr[i] candies

Form thr N pairs such that sum of absolute differences of chocolate and Candies in the ith pair is minimised;

*/

int FormPairs(int i, int j, int n, int m, vector<int> &choco, vector<int> &cand, vector<vector<int>> &dp)
{
    if (i >= n)
        return 0;

    if (j >= m)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    int op1, op2;

    op1 = abs(choco[i] - cand[j]) + FormPairs(i + 1, j + 1, n, m, choco, cand, dp);
    op2 = FormPairs(i, j + 1, n, m, choco, cand, dp);

    return dp[i][j] = min(op1, op2);
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> choco(n);

    vector<int> cand(m);

    for (int i = 0; i < n; i++)
        cin >> choco[i];

    for (int i = 0; i < m; i++)
        cin >> cand[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    sort(choco.begin(), choco.end());
    sort(cand.begin(), cand.end());

    return FormPairs(0, 0, n, m, choco, cand, dp);
}