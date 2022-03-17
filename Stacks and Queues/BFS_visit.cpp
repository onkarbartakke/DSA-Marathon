#include <bits/stdc++.h>

using namespace std;

int minJumps(vector<int> &arr)
{

    int i, j, n;
    n = arr.size();

    vector<int> visited(n, false);

    queue<int> qu;

    unordered_map<int, vector<int>> mp;

    for (i = 0; i < n; i++)
        mp[arr[i]].push_back(i);

    int steps = 0;

    if (n == 0 || n == 1)
        return 0;

    qu.push(0);
    visited[0] = true;

    while (!qu.empty())
    {
        int sz = qu.size();

        while (sz--)
        {
            int u = qu.front();
            qu.pop();

            if (u == n - 1)
                return steps;

            if (u + 1 < n && !visited[u + 1])
            {
                qu.push(u + 1);
                visited[u + 1] = true;
                if (u + 1 == n - 1)
                    return steps + 1;
            }

            if (u - 1 >= 0 && !visited[u - 1])
            {
                qu.push(u - 1);
                visited[u - 1] = true;
            }

            for (auto it : mp[arr[u]])
            {
                if (it != u && !visited[it])
                {
                    qu.push(it);
                    visited[it] = true;
                    if (it == n - 1)
                        return steps + 1;
                }
            }
        }

        steps++;
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;
    
}