#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    unordered_map<int, vector<pair<int, int>>> ancestors;

    int gcd(int a, int b)
    {
        if (a == 0)
            return b;

        if (a == 1 || b == 1)
            return 1;

        if (a % b == 0)
            return b;

        if (b % a == 0)
            return a;

        int r = a % b;

        return gcd(b, r);
    }

    void traverse(vector<vector<int>> &graph, unordered_map<int, vector<int>> &cops, int i, int parent, int level, vector<int> &ans, vector<int> &nums)
    {
        int max_level = -1;

        for (auto cop : cops[nums[i]])
        {
            auto v = ancestors[cop];

            if (!v.empty() && v.back().first > max_level)
            {
                ans[i] = v.back().second;
                max_level = v.back().first;
            }
        }

        ancestors[nums[i]].push_back({level, i});

        for (auto child : graph[i])
        {
            if (child != parent)
                traverse(graph, cops, child, i, level + 1, ans, nums);
        }

        ancestors[nums[i]].pop_back();
    }
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {

        unordered_map<int, vector<int>> coprimes;

        unordered_set<int> s(begin(nums), end(nums));
        for (auto n1 : s)
        {
            for (auto n2 : s)
            {
                if (__gcd(n1, n2) == 1)
                    coprimes[n1].push_back(n2);
            }
        }
        int n = nums.size();

        vector<vector<int>> graph(n);

        for (auto v : edges)
        {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        vector<int> ans(n, -1);

        traverse(graph, coprimes, 0, 0, 0, ans, nums);

        return ans;
    }

    //almost same approach
    unordered_map<int, vector<int>> cops;

    unordered_map<int, vector<pair<int, int>>> ancestors;

    void traverse1(vector<int> &n, vector<vector<int>> &al, int i, int parent, int level, vector<int> &res)
    {
        int max_level = -1;
        for (auto cop : cops[n[i]])
        {
            auto &v = ancestors[cop];
            if (!v.empty() && v.back().first > max_level)
            {
                max_level = v.back().first;
                res[i] = v.back().second;
            }
        }
        ancestors[n[i]].push_back({level, i});
        for (auto child : al[i])
            if (child != parent)
                traverse1(n, al, child, i, level + 1, res);
        ancestors[n[i]].pop_back();
    }
    vector<int> getCoprimes1(vector<int> &n, vector<vector<int>> &edges)
    {
        unordered_set<int> s(begin(n), end(n));
        for (auto n1 : s)
        {
            for (auto n2 : s)
                if (__gcd(n1, n2) == 1)
                    cops[n1].push_back(n2);
        }
        vector<vector<int>> al(n.size());
        vector<int> res(n.size(), -1);
        for (auto &e : edges)
        {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        traverse1(n, al, 0, 0, 0, res);
        return res;
    }
};