#include <bits/stdc++.h>
#define LOG 20
using namespace std;

vector<vector<int>> up(10000, vector<int>(LOG + 1, 0));
vector<int> depth(10000, 0);

void DFS(int u, unordered_map<int, vector<int>> &mp)
{
    for (auto child : mp[u])
    {
        depth[child] = depth[u] + 1;
        up[child][0] = u;

        for (int i = 1; i <= LOG; i++)
        {
            up[child][i] = up[up[child][i - 1]][i - 1];
        }

        DFS(child, mp);
    }
}

int getLCA(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);

    int k = depth[b] - depth[a];

    for (int i = LOG; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            a = up[a][i];
        }
    }

    if (a == b)
        return a;

    for (int i = LOG; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}
int main()
{
    int n;

    cin >> n;

    unordered_map<int, vector<int>> mp;

    for (int v = 0; v < n; v++)
    {
        int cnt;
        cin >> cnt;

        for (int c = 0; c < cnt; c++)
        {
            int child;

            cin >> child;

            mp[v].push_back(child);
        }
    }

    depth[0] = 0;
    DFS(0, mp);

    int q;

    cin >> q;

    while (q--)
    {
        int a, b;

        cin >> a >> b;

        cout << getLCA(a, b) << "\n";
    }
}