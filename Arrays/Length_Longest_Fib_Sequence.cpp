#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    int lenLongestFibSubseq(vector<int> &A)
    {
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = i + 1; j < A.size(); ++j)
            {
                int a = A[i], b = A[j], l = 2;
                while (s.count(a + b))
                    b = a + b, a = b - a, l++;
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
};

// DP Solution
class Solution2
{
public:
    int lenLongestFibSubseq(vector<int> &A)
    {
        int n = A.size();
        map<int, int> m;
        for (int i = 0; i < n; i++)
            m[A[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int j = 1; j < n; j++)
            for (int i = 0; i < j; i++)
                if (m.find(A[j] - A[i]) != m.end() and m[A[j] - A[i]] < i)
                    dp[i][j] = max(dp[i][j], dp[m[A[j] - A[i]]][i] + 1);
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, dp[i][j]);

        return (ans == 2) ? 0 : ans;
    }
};