#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts)
    {

        int r1 = min(startPos[0], homePos[0]);
        int r2 = max(startPos[0], homePos[0]);

        int c1 = min(startPos[1], homePos[1]);
        int c2 = max(startPos[1], homePos[1]);

        int cost = 0;
        if (r1 == startPos[0])
        {
            for (int i = r1 + 1; i <= r2; i++)
                cost += rowCosts[i];
        }
        else
        {
            for (int i = r2 - 1; i >= r1; i--)
                cost += rowCosts[i];
        }

        if (c1 == startPos[1])
        {
            for (int i = c1 + 1; i <= c2; i++)
                cost += colCosts[i];
        }
        else
        {
            for (int i = c2 - 1; i >= c1; i--)
                cost += colCosts[i];
        }

        return cost;
    }
};