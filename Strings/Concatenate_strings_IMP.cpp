#include <bits/stdc++.h>

using namespace std;
/*
You are given a string s, an integer k, a letter letter, and an integer repetition.

Return the lexicographically smallest subsequence of s of length k that has the letter letter appear at least repetition times.
The test cases are generated so that the letter appears in s at least repetition times.

A subsequence is a string that can be derived from another string by deleting some or no
characters without changing the order of the remaining characters.

A string a is lexicographically smaller than a string b if in the first position where a and b differ,
string a has a letter that appears earlier in the alphabet than the corresponding letter in b.


 */
class Solution
{
public:
    bool contains(string s, unordered_set<string> &st)
    {
        for (int i = 1; i < s.length(); i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (st.find(left) != st.end())
            {
                if (st.find(right) != st.end() || contains(right, st))
                    return true;
            }
        }

        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {

        unordered_set<string> st(words.begin(), words.end());

        vector<string> ans;
        for (auto s : words)
        {
            if (contains(s, st))
            {
                ans.push_back(s);
            }
        }

        return ans;
    }
};

// DP approach
vector<string> findAllConcatenatedWordsInADict1(vector<string> &words)
{
    unordered_set<string> s(words.begin(), words.end());
    vector<string> res;
    for (auto w : words)
    {
        int n = w.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == 0)
                continue;
            for (int j = i + 1; j <= n; j++)
            {
                if (j - i < n && s.count(w.substr(i, j - i)))
                    dp[j] = 1;
            }
            if (dp[n])
            {
                res.push_back(w);
                break;
            }
        }
    }
    return res;
}

// Trie Approach

class Trie
{
public:
    vector<Trie *> next;
    bool isend;
    Trie()
    {
        isend = false;
        next.resize(26);
    }
};

class Solution1
{
public:
    void addword(Trie *head, string &w)
    {
        for (int i = 0; i < w.length(); i++)
        {
            if (!head->next[w[i] - 'a'])
                head->next[w[i] - 'a'] = new Trie();
            head = head->next[w[i] - 'a'];
        }
        head->isend = true;
    }

    bool searchword(Trie *head, string &w, int idx = 0, int words = 0)
    {
        Trie *curr = head;

        for (int i = idx; i < w.length(); i++)
        {
            if (!head->next[w[i] - 'a'])
                return false;
            head = head->next[w[i] - 'a'];
            if (i != w.length() - 1 && head->isend && searchword(curr, w, i + 1, words + 1))
                return true;
        }
        words += 1;
        return words > 1 && head->isend;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        Trie *head = new Trie();
        vector<string> ans;
        for (string w : words)
        {
            addword(head, w);
        }
        for (string w : words)
        {
            if (searchword(head, w))
                ans.push_back(w);
        }
        return ans;
    }
};