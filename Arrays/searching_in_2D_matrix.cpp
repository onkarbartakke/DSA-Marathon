#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int r, c, l, h, m;
        r = matrix.size();
        c = matrix[0].size();
        int i, j;
        l = 0;
        h = (r * c) - 1;
        int mat;
        while (l <= h)
        {
            m = l + (h - l) / 2;

            i = m / c;
            j = m % c;
            mat = matrix[i][j];

            if (mat == target)
                return true;
            else if (mat < target)
                l = m + 1;
            else
                h = m - 1;
        }

        return false;
    }

    /*
    Another Approach

      int i,j;
        i = 0;
        j = matrix[0].size()-1;
        int r = matrix.size();
        while(i<r && j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            
            if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
        }
        
        return false;
    */
};