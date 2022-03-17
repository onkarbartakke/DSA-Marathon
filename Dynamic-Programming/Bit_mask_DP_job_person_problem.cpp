#include <bits/stdc++.h>

using namespace std;
/*
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20

*/

int solve(int i, int n, int mask, vector<vector<int>> &dp)
{
    if (i >= n)
        return 0;

    if (dp[i][mask] != -1)
        return dp[i][mask];

    int ans = INT_MAX;

    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
            ans = min(ans, cost[j][i] + solve(i + 1, n, (mask ^ (1 << j)), dp))
    }

    return dp[i][mask] = ans;
}

int main()
{
    int n;
    cout << "Enter the value of N : ";
    cin >> n;

    int cost[n][n];
    cout << "\nEnter the cost person matrix : \n";

    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    int mask = (1 << n) - 1;
    cout << "\n\nMost Optimal distrubtion of Jobs gives us cost : " << solve(0, n, mask, dp);
}
