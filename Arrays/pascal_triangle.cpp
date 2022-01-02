#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1)
            return ans;

        int i = 2;

        while (i <= numRows)
        {
            if (i == 2)
            {
                ans.push_back({1, 1});
                i++;
                continue;
            }

            vector<int> v;
            v.push_back(1);

            vector<int> prev = ans.back();

            for (int j = 1; j < prev.size(); j++)
            {
                v.push_back(prev[j] + prev[j - 1]);
            }

            v.push_back(1);
            ans.push_back(v);
            i++;
        }

        return ans;
    }
};