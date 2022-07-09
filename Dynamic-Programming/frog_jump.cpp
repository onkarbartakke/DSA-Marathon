#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    //Recursive function giving TLE
    bool solve(int ind, int k, vector<int> &stones, unordered_map<int, int> &mp, vector<int> &dp)
    {
        if (dp[ind] == 1)
            return true;

        if (ind == stones.size() - 1)
        {
            dp[ind] = 1;
            return true;
        }

        int op1 = k - 1;
        int op2 = k;
        int op3 = k + 1;

        bool r1 = false, r2 = false, r3 = false;
        if (op1 > 0)
        {
            int newPos = stones[ind] + op1;
            if (mp.find(newPos) != mp.end())
            {
                int idx = mp[newPos];
                r1 = solve(idx, op1, stones, mp, dp);

                if (r1 == true)
                {
                    dp[ind] = 1;
                    return true;
                }
            }
        }

        if (op2 > 0)
        {
            int newPos = stones[ind] + op2;
            if (mp.find(newPos) != mp.end())
            {
                int idx = mp[newPos];
                r2 = solve(idx, op2, stones, mp, dp);

                if (r2 == true)
                {
                    dp[ind] = 1;
                    return true;
                }
            }
        }

        int newPos = stones[ind] + op3;

        if (mp.find(newPos) != mp.end())
        {
            int idx = mp[newPos];
            r3 = solve(idx, op3, stones, mp, dp);

            if (r3 == true)
            {
                dp[ind] = 1;
                return true;
            }
        }

        dp[ind] = 0;
        return false;
    }

    bool canCross(vector<int> &stones)
    {
        //         unordered_map<int,int>mp;
        //         int n = stones.size();
        //         vector<int>dp(n,-1);

        //         for(int i = 0 ; i < stones.size() ; i++)
        //         {
        //             mp[stones[i]] = i;
        //         }

        //         return solve(0,0,stones,mp,dp);

        int n = stones.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        dp[0][1] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int gap = stones[i] - stones[j];

                if (gap < 0 || gap > n || !dp[j][gap])
                    continue;

                dp[i][gap] = true;

                if (gap - 1 >= 0)
                    dp[i][gap - 1] = true;
                if (gap + 1 <= n)
                    dp[i][gap + 1] = true;

                if (i == n - 1)
                    return true;
            }
        }

        return false;
    }
};