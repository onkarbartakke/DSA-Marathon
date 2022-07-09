#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int LIS_size(vector<int> &A)
    {
        vector<int> si;

        for (int i = 0; i < A.size(); i++)
        {
            if (si.empty() || A[i] > si.back())
                si.push_back(A[i]);
            else
            {
                int idx = lower_bound(si.begin(), si.end(), A[i]) - si.begin();
                si[idx] = A[i];
            }
        }

        return si.size();
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        unordered_map<char, vector<int>> pos;

        for (int i = text2.size() - 1; i >= 0; i--)
        {
            pos[text2[i]].push_back(i);
        }

        vector<int> A;

        for (int i = 0; i < text1.size(); i++)
        {
            if (pos.find(text1[i]) != pos.end())
            {
                vector<int> v = pos[text1[i]];

                for (auto idx : v)
                    A.push_back(idx);
            }
        }

        int si = LIS_size(A);

        return si;
    }
};