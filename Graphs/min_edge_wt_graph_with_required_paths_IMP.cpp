#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<long> Dikstra(vector<vector<vector<long>>> &G, int start)
    {
        int n = G.size();

        vector<long> ans(n, LONG_MAX);

        ans[start] = 0;

        set<pair<long, long>> st;

        for (long i = 0; i < n; i++)
            st.insert({LONG_MAX, i});

        st.erase({LONG_MAX, start});
        st.insert({0, start});

        while (!st.empty())
        {
            auto p = (*st.begin());

            long u = p.second;
            long cost = p.first;
            st.erase({cost, u});

            if (cost == LONG_MAX)
                break;
            for (auto v : G[u])
            {
                int dest = v[0];
                int wt = v[1];

                if (ans[dest] > wt + cost)
                {
                    st.erase({ans[dest], dest});
                    ans[dest] = wt + cost;
                    st.insert({ans[dest], dest});
                }
            }
        }

        return ans;
    }


    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {

        vector<vector<vector<long>>> G(n);
        for (auto v : edges)
        {
            G[v[0]].push_back({v[1], v[2]});
        }

        vector<long> s1 = Dikstra(G, src1);
        vector<long> s2 = Dikstra(G, src2);

        vector<vector<vector<long>>> R(n);  //Reversing the graph

        for (auto v : edges)
        {
            R[v[1]].push_back({v[0], v[2]});
        }

        vector<long> d = Dikstra(R, dest);

        long long ans = LONG_MAX;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != LONG_MAX && s2[i] != LONG_MAX && d[i] != LONG_MAX)
            {
                long long u = (long long)s1[i] + s2[i] + d[i];
                ans = min(ans, u);
            }
        }

        if (ans == LONG_MAX)
            return -1;
        else
            return ans;
    }
};