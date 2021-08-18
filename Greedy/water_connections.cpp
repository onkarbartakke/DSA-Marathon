#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
    // code here
    int i, j;
    vector<bool> incoming(n + 1, false);

    vector<vector<int>> adj(n + 1);

    for (i = 0; i < b.size(); i++)
    {
        incoming[b[i]] = true;

        if (adj[a[i]].size() == 0)
        {
            adj[a[i]].push_back(b[i]);
            adj[a[i]].push_back(d[i]);
        }
        else
        {
            if (d[i] < adj[a[i]][1])
            {
                adj[a[i]][0] = b[i];
                adj[a[i]][1] = d[i];
            }
        }
    }

    vector<vector<int>> ans;
    for (i = 1; i <= n; i++)
    {
        if (incoming[i] == false && adj[i].size() != 0)
        {
            vector<int> v;
            v.push_back(i);
            int m = INT_MAX;
            j = i;
            while (adj[j].size() != 0)
            {
                m = min(m, adj[j][1]);
                j = adj[j][0];
            }

            v.push_back(j);
            v.push_back(m);

            ans.push_back(v);

            //incoming[i]=true;
        }
    }

    return ans;
}