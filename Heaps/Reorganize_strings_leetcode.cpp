#include<bits/stdc++.h>

using namespace std;

string reorganizeString(string s)
{

    unordered_map<char, int> mp;

    int i, j, n;
    n = s.length();

    for (i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pq.push({it->second, it->first});
    }

    string ans = "";

    while (!pq.empty())
    {
        pair<int, char> p = pq.top();
        pq.pop();

        if (pq.empty())
        {
            if (p.first > 1)
                return "";
            else
                return (ans + p.second);
        }

        pair<int, char> q = pq.top();
        pq.pop();

        ans = ans + p.second + q.second;

        if (p.first > 1)
            pq.push({p.first - 1, p.second});

        if (q.first > 1)
            pq.push({q.first - 1, q.second});
    }

    return ans;
}

int main()
{
}