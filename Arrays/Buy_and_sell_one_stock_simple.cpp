#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int maxProfit(vector<int> &prices)
    {

        int mini = INT_MAX;
        int maxpro = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            mini = min(prices[i], mini);
            maxpro = max(maxpro, prices[i] - mini);
        }

        return maxpro;
    }
};
