#include <bits/stdc++.h>

using namespace std;
/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make 
the input string valid.

Return all the possible results. You may return the answer in any order.
*/
class Solution
{
public:
    void GetValidStrings(int ind, int left_remove, int right_remove, int pair, string path, unordered_set<string> &st, string &s)
    {
        if (ind >= s.length())
        {
            if (left_remove == 0 && right_remove == 0 && pair == 0)
            {
                st.insert(path);
            }

            return;
        }

        if (s[ind] == '(')
        {
            if (left_remove > 0)
                GetValidStrings(ind + 1, left_remove - 1, right_remove, pair, path, st, s);

            GetValidStrings(ind + 1, left_remove, right_remove, pair + 1, path + s[ind], st, s);
        }
        else if (s[ind] == ')')
        {
            if (right_remove > 0)
                GetValidStrings(ind + 1, left_remove, right_remove - 1, pair, path, st, s);

            if (pair > 0)
                GetValidStrings(ind + 1, left_remove, right_remove, pair - 1, path + s[ind], st, s);
        }
        else
            GetValidStrings(ind + 1, left_remove, right_remove, pair, path + s[ind], st, s);
    }

    
    vector<string> removeInvalidParentheses(string s)
    {

        int left_remove = 0, right_remove = 0, i, n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                left_remove++;
            else if (s[i] == ')')
            {
                if (left_remove > 0)
                    left_remove--;
                else
                    right_remove++;
            }
        }

        unordered_set<string> st;

        GetValidStrings(0, left_remove, right_remove, 0, "", st, s);

        return vector<string>(st.begin(), st.end());
    }
};

//https://leetcode.com/problems/remove-invalid-parentheses/discuss/75048/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explaination