#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 10000007


/*
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. 
The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring,
 the answer is "".
*/
class Solution
{
public:
    string match(string &s, int maxLen, vector<ll> &roll)
    {
        unordered_map<ll, vector<int>> hash;
        ll win = 0;

        for (int i = 0; i < maxLen; i++)
        {
            win = ((win * 26) % mod + (s[i] - 'a')) % mod;
        }

        hash[win].push_back(0);
        // cout<<"0  "<<win<<"\n";
        for (int i = maxLen; i < s.length(); i++)
        {
            // win = ((win - roll[maxLen-1]*(s[i-maxLen]-'a'))%mod    )%mod;

            win = ((win - (roll[maxLen - 1] * (s[i - maxLen] - 'a')) % mod) + mod) % mod;
            // win = (win*26 + s[i]-'a')%mod;

            win = (win * 26 % mod + s[i] - 'a') % mod;

            // cout<<i-maxLen+1<<"  "<<win<<"\n";
            if (hash.find(win) != hash.end())
            {
                bool match = false;

                auto v = hash[win];

                for (auto it : v)
                {
                    string p = s.substr(it, maxLen);
                    string q = s.substr(i - maxLen + 1, maxLen);

                    if (p.compare(q) == 0)
                        return p;
                }
            }

            hash[win].push_back(i - maxLen + 1);
        }

        return "";
    }

    string longestDupSubstring(string s)
    {

        int n = s.length();

        vector<ll> roll(n);

        roll[0] = 1;

        for (int i = 1; i < n; i++)
        {
            roll[i] = (26 * roll[i - 1]) % mod;
        }

        int low = 1, high = n, mid;
        int idx = -1, len = 0;

        string ret = "";
        while (low <= high)
        {
            mid = (low + high) / 2;

            string ans = match(s, mid, roll);
            // cout<<ans<<" "<<mid<<"\n";
            if (ans.length() > len)
            {
                len = ans.length();
                ret = ans;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ret;
    }
};