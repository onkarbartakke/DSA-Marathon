#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    double p;

    bool dfs(int parent, int curr, int t, unordered_map<int, vector<int>> &mp, int target, double prob)
    {
        if (t < 0)
            return false;

        if (curr == target && t == 0)
        {
            p = prob;
            return true;
        }

        if (curr == target && t > 0 && mp[curr].size() == 1)
        {
            p = prob;
            return true;
        }

        int n = mp[curr].size();
        n = n - 1;

        auto v = mp[curr];

        for (auto it : v)
        {
            if (it != parent)
            {
                if (dfs(curr, it, t - 1, mp, target, prob / n))
                    return true;
            }
        }

        return false;
    }
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {

        unordered_map<int, vector<int>> mp;

        for (auto v : edges)
        {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        if (target == 1 && t == 0)
            return 1.0;
        if (target == 1 && t > 0 && mp[1].size() == 0)
            return 1.0;
        if (target == 1 && t > 0 && mp[1].size() > 0)
            return 0.0;
        else
        {
            p = 0.0;
            auto v = mp[1];

            int n = v.size();

            for (auto it : v)
            {
                if (dfs(1, it, t - 1, mp, target, (1.0 / n)))
                    return p;
            }
        }

        return p;
    }
};

int main()
{
}