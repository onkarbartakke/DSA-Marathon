#include <bits/stdc++.h>

using namespace std;


/*
ou are given a 0-indexed array of n integers arr.

The interval between two elements in arr is defined as the absolute difference between their indices. More formally, the interval
 between arr[i] and arr[j] is |i - j|.

Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each element in arr with the
 same value as arr[i].

Note: |x| is the absolute value of x.
*/
class Solution
{
    public:
    vector<long long> getDistances(vector<int> &arr)
    {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }

        int n = arr.size();

        vector<long long> pre(n, 0), suf(n, 0), ans(n, 0);

        for (auto it : mp)
        {
            vector<int> v = it.second;

            for (int i = 1; i < v.size(); i++)
                pre[v[i]] = pre[v[i - 1]] + (long long)i * (v[i] - v[i - 1]);

            for (int i = v.size() - 2; i >= 0; i--)
                suf[v[i]] = suf[v[i + 1]] + (long long)(v.size() - 1 - i) * (v[i + 1] - v[i]);
        }

        for (int i = 0; i < n; i++)
            ans[i] += (pre[i] + suf[i]);

        return ans;
    }
};

int main()
{
}