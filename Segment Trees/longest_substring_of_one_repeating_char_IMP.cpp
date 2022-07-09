#include <bits/stdc++.h>

using namespace std;

/*
You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and
a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

Return an array lengths of length k where lengths[i] is the length of the longest substring of s
consisting of only one repeating character after the ith query is performed.
*/
class Solution
{
public:
    struct Node
    {
        // public:
        char lc, rc;
        int suf = 0, pref = 0, longest = 0, sz = 1;

        void merge(Node &l, Node &r)
        {
            longest = max(l.longest, r.longest);

            if (l.rc == r.lc)
                longest = max(longest, l.suf + r.pref);

            sz = l.sz + r.sz;

            lc = l.lc;
            rc = r.rc;

            pref = l.pref + (l.pref == l.sz && l.lc == r.lc ? r.pref : 0);
            suf = r.suf + (r.suf == r.sz && r.rc == l.rc ? l.suf : 0);
        }
    };

    void Build(string &s, int low, int high, int ind, vector<Node> &seg)
    {
        if (low > high)
            return;

        if (low == high)
        {
            seg[ind].lc = seg[ind].rc = s[low];
            seg[ind].longest = seg[ind].pref = seg[ind].suf = seg[ind].sz = 1;
            return;
        }

        int mid = (low) + (high - low) / 2;

        Build(s, low, mid, 2 * ind + 1, seg);
        Build(s, mid + 1, high, 2 * ind + 2, seg);

        seg[ind].merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(string &s, int low, int high, int ind, vector<Node> &seg, int i, char val)
    {
        if (low == high)
        {
            s[low] = val;
            seg[ind].lc = seg[ind].rc = s[low];

            return seg[ind].longest;
        }

        int mid = low + (high - low) / 2;

        if (i <= mid)
            query(s, low, mid, 2 * ind + 1, seg, i, val);
        else
            query(s, mid + 1, high, 2 * ind + 2, seg, i, val);

        seg[ind].merge(seg[2 * ind + 1], seg[2 * ind + 2]);

        return seg[ind].longest;
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {

        int n = s.length();

        vector<Node> seg(4 * n + 1);

        vector<int> ans;

        Build(s, 0, n - 1, 0, seg);

        for (int i = 0; i < queryIndices.size(); i++)
        {
            ans.push_back(query(s, 0, n - 1, 0, seg, queryIndices[i], queryCharacters[i]));
        }

        return ans;
    }
};