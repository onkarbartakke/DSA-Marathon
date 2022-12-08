#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int Kadens(vector<int> &arr)
    {
        int n = arr.size();

        int curr_max, globalMax = arr[0];

        curr_max = arr[0];

        for (int i = 1; i < n; i++)
        {
            curr_max = max(arr[i], curr_max + arr[i]);
            globalMax = max(globalMax, curr_max);
        }

        return globalMax;
    }

    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        // code here

        int ans = INT_MIN;
        int x, y;

        for (int i = 0; i < C; i++)
        {
            vector<int> arr(R, 0);

            for (int j = i; j < C; j++)
            {
                for (int k = 0; k < R; k++)
                {
                    arr[k] += M[k][j];
                }

                ans = max(ans, Kadens(arr));
            }
        }

        // cout<<x<<"  - "<<y<<"\n";
        return ans;
    }
};