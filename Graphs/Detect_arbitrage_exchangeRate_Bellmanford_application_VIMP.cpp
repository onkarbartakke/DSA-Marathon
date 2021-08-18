#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

bool detectArbitrage(vector<vector<double>> exchangeRates)
{
    // Write your code here.
    int n, i, j, k;
    n = exchangeRates.size();
    vector<vector<double>> edges(n, vector<double>(n));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            edges[i][j] = (-1) * log(exchangeRates[i][j]);
        }
    }

    //Bellaman ford

    vector<double> cost(n, DBL_MAX);

    cost[0] = 0.0;
    bool b = false;
    for (i = 0; i < n - 1; i++)
    {
        b = false;
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (k == j)
                    continue;

                if (cost[j] != DBL_MAX && cost[k] > cost[j] + edges[j][k])
                {
                    cost[k] = cost[j] + edges[j][k];
                    b = true;
                }
            }
        }

        if (b == false)
            return false;
    }

    b = false;
    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            if (k == j)
                continue;

            if (cost[j] != DBL_MAX && cost[k] > cost[j] + edges[j][k])
            {
                cost[k] = cost[j] + edges[j][k];
                b = true;
                return true;
            }
        }
    }

    return false;
}

int main()
{
}