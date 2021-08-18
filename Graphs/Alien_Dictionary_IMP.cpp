#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void toposort(stack<int> &st, vector<vector<int>> &adj, int start, vector<bool> &visited)
{
    visited[start] = true;

    for (auto i : adj[start])
    {
        if (!visited[i])
        {
            toposort(st, adj, i, visited);
        }
    }

    st.push(start);
}

string findOrder(string dict[], int N, int K)
{
    //code here
    int i, j, k;
    vector<vector<int>> adj(26);
    //vector<int>incoming(K,0);
    vector<bool> present(26, false);
    for (i = 0; i < N - 1; i++)
    {
        string s = dict[i];
        string p = dict[i + 1];

        for (j = 0; j < min(s.length(), p.length()); j++)
        {
            if (s[j] != p[j])
            {
                adj[s[j] - 'a'].push_back(p[j] - 'a');
                //incoming[p[j]-'a']++;
                present[s[j] - 'a'] = true;
                present[p[j] - 'a'] = true;
                break;
            }
        }
    }

    string ans = "";
    stack<int> st;
    vector<bool> visited(26, false);

    for (i = 0; i < 26; i++)
    {
        if (present[i] && !visited[i])
        {
            toposort(st, adj, i, visited);
        }
    }

    while (!st.empty())
    {
        char c = 'a' + st.top();
        ans = ans + c;
        st.pop();
    }

    return ans;
}

int main()
{
    
}