#include <bits/stdc++.h>

using namespace std;
/*
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the left of nums[i].
*/
class Solution
{
public:
    void Merge(vector<int> &ans, vector<pair<int, int>> &v, int left, int mid, int right)
    {
        vector<pair<int, int>> tmp(right - left + 1);

        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right)
        {
            if (v[i].first < v[j].first)
            {
                ans[v[j].second] += mid - i + 1;
                tmp[k++] = v[j++];
            }
            else
            {
                tmp[k++] = v[i++];
            }
        }

        while (i <= mid)
            tmp[k++] = v[i++];

        while (j <= right)
            tmp[k++] = v[j++];

        for (int i = left; i <= right; i++)
        {
            v[i] = tmp[i - left];
        }
    }

    void MergeSort(vector<int> &ans, vector<pair<int, int>> &v, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            MergeSort(ans, v, left, mid);
            MergeSort(ans, v, mid + 1, right);

            Merge(ans, v, left, mid, right);
        }
    }

    vector<int> countSmaller(vector<int> &nums)
    {

        int n = nums.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }

        vector<int> ans(n, 0);

        MergeSort(ans, v, 0, n - 1);

        return ans;
    }
};