#include <bits/stdc++.h>

using namespace std;

/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations
 in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

*/
class Solution
{
    public:
    void FindCombination(int ind, vector<int> &arr, int t, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (t == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++)
        {
            if (i != ind && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > t)
                break;

            ds.push_back(arr[i]);
            FindCombination(i + 1, arr, t - arr[i], ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> ds;

        FindCombination(0, arr, target, ds, ans);

        return ans;
    }
};