#include <bits/stdc++.h>

using namespace std;
/*
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

 
 */
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {

        string ans = "0";

        vector<int> cnt(256, 0);

        for (auto c : s)
            cnt[c]++;

        vector<int> visited(256, false);
        for (auto c : s)
        {
            cnt[c]--;

            if (visited[c])
                continue;

            while (c < ans.back() && cnt[ans.back()] > 0)
            {
                visited[ans.back()] = false;
                //  cnt[ans.back()]++;

                ans.pop_back();
            }

            ans += c;
            visited[c] = true;
        }

        return ans.substr(1);
    }
};