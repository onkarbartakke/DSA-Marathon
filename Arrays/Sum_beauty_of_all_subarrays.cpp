#include <bits/stdc++.h>

using namespace std;


/*

Given an arr of length n, the beauty of any of its subarray is 
the number of elements in the subarray that occurs exactly once. 

Give sum of beauty of all possible subarrays

*/
long long calcBeauty(int n, vector<int> arr)
{
    // code here
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        int it = arr[i];

        if (mp.find(it) == mp.end())
            mp[it].push_back(-1);

        mp[it].push_back(i);
    }

    for (auto it : mp)
    {
        mp[it.first].push_back(n);
    }

    long long ans = 0;

    for (auto it : mp)
    {
        auto ls = it.second;

        for (int i = 1; i < ls.size() - 1; i++)
        {
            long long left = ls[i] - ls[i - 1];
            long long right = ls[i + 1] - ls[i];

            ans += (left * right);
        }
    }

    return ans;
}
int main()
{
}