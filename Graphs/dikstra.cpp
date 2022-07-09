#include <vector>
#include <set>
#include<iostream>
#include <climits>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges)
{
    // Write your code here;
    int n, i, j, u, v;
    v = edges.size();
    //map<int,int>mp;
    set<pair<int, int>> mp;
    for (i = 0; i < v; i++)
    {
        mp.insert({INT_MAX, i});
    }

    mp.erase({INT_MAX, start});
    mp.insert({0, start});

    vector<int> ans(v, INT_MAX);
    ans[start] = 0;
    while (!mp.empty())
    {
        auto it = (*mp.begin());
        u = it.second;
        int cost = it.first;
        //ans[u]=cost;
        mp.erase({cost, u});
        if (edges[u].size() == 0)
            continue;
        for (auto v : edges[u])
        {
            int dest = v[0];
            if (ans[dest] > v[1] + cost)
            {
                mp.erase({ans[dest], dest});
                ans[dest] = v[1] + cost;
                mp.insert({ans[dest], dest});
            }
        }

        for (i = 0; i < v; i++)
        {
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }
        return ans;
    }
}

int main()
{
    
}