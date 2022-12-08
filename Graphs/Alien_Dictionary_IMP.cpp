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
    // code here
    int i, j, k;
    vector<vector<int>> adj(26);
    // vector<int>incoming(K,0);
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
                // incoming[p[j]-'a']++;
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

/*
So what is wrong bro??
U have been sad for long time, I know u r strong but y so sad tell me lets figure this out.

In that grp is there anyone who closely wants to understand u?
Know u?
or is there anyone who will firmly stand behinde you??

I guess that ans is mostly NO

Everyone wants to connect with her, there is something in her that makes her feel wanted.
And I am not like that all, I have closely observed the situation.

Now what I only want is a top class placement and satisfaction.

God please save me from this, I am sorry for the 100th time if I have been wrong but please god save me from facing all this.

Please god save.


**/
/*
#define mod 1000000007
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {

        // unordered_set<int>st(arr.begin() , arr.end());

        sort(arr.begin(), arr.end());

        int n = arr.size();

        unordered_map<long long, long long> mp;

        long long res = 1;

        mp[arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            int root = arr[i];
            long long curr = 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && mp.find(root / arr[j]) != mp.end())
                {
                    curr = (curr + (mp[arr[j]] * mp[arr[root / arr[j]]]) % mod) % mod;
                }
            }

            mp[arr[i]] = curr;
            res = (res + curr) % mod;
            // cout<<res<<"\n";
        }

        //  res = 0;

        return (int)res % mod;
    }
};

*/