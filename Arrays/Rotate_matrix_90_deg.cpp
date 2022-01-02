#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    void rotate(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};