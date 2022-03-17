#include <bits/stdc++.h>

using namespace std;

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where 
the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at 
least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution
{
    public:
    void FindCombination(int ind, vector<int> &cd, int t, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (ind >= cd.size())
        {
            if (t == 0)
            {
                ans.push_back(ds);
            }

            return;
        }

        // Pick the element and stay there

        if (cd[ind] <= t)
        {
            ds.push_back(cd[ind]);
            FindCombination(ind, cd, t - cd[ind], ds, ans);
            ds.pop_back();
        }

        //Dont pick and move ahead

        FindCombination(ind + 1, cd, t, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> ds;

        FindCombination(0, candidates, target, ds, ans);

        return ans;
    }
};