#include <bits/stdc++.h>

using namespace std;
/*
You are given a string s and an integer repeatLimit. 
Construct a new string repeatLimitedString using the characters of s such that no letter appears more than 
repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, 
string a has a letter that appears later in the alphabet than the corresponding letter in b. 
If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
*/
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {

        vector<int> cnt(26, 0);

        for (int i = 0; i < s.length(); i++)
        {
            cnt[s[i] - 'a']++;
        }

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0)
            {
                pq.push({i, cnt[i]});
            }
        }

        string ans = "";

        while (!pq.empty())
        {
            int ch1 = pq.top().first;
            int f1 = pq.top().second;
            pq.pop();

            if (ans.length() == 0 || ans.back() != (char)(ch1 + 'a'))
            {
                int times = min(f1, repeatLimit);

                char c = (char)(ch1 + 'a');

                for (int i = 0; i < times; i++)
                    ans += c;

                f1 -= times;

                if (f1 > 0)
                {
                    pq.push({ch1, f1});
                }
            }
            else
            {
                if (pq.empty())
                    return ans;

                int ch2 = pq.top().first;
                int f2 = pq.top().second;
                pq.pop();

                char c = (char)(ch2 + 'a');

                ans += c;
                f2--;

                if (f2 > 0)
                {
                    pq.push({ch2, f2});
                }

                pq.push({ch1, f1});
            }
        }

        return ans;
    }
};