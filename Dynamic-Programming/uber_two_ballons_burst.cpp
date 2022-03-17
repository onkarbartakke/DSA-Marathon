#include <bits/stdc++.h>

using namespace std;
long long int solve(vector<int> &a)
{
    long long int INF = 1e9 + 7, i, j, left, right, k;

    int n = a.size();
    a.insert(a.begin(), 1);
    a.push_back(1);

    int win;
    int last = a.size() - 2;

    int N = a.size();

    vector<vector<long long int>> dp(N, vector<long long int>(N, 0));
    cout << "\nStating DP\n";
    for (win = 1; win <= n; win++)
    {
        cout << "\n WIn : " << win << "\n";
        for (left = 1; left + win - 1 <= last; left++)
        {
            right = left + win - 1;

            for (k = left; k < right; k = k+2)
            {
                dp[left][right] = max(dp[left][right], (a[left - 1] * a[k] * (right+2 < N ? a[right+2] : 0) * a[right + 1]) + dp[left][k-1] + dp[k+1][right]);
            }

            cout<<"Left : "<<left<<"  Right : "<<right<<" val "<<dp[left][right]<<"\n\n";
        }
    }

    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            cout<<dp[i][j]<<" ";
        }

        cout<<"\n";
    }
    return dp[1][n];
}
int main()
{
    int n, i;
    cin >> n;

    vector<int> a(n);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\narr input done\n";
    long long int ans = solve(a);

    cout << "\n\n***\n"
         << ans;
}