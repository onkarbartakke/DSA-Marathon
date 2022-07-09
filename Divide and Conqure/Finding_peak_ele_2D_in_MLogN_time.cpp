#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {

        int startCol = 0, endCol = mat[0].size() - 1, midCol, row, maxRow;

        while (startCol <= endCol)
        {
            midCol = startCol + (endCol - startCol) / 2;

            row = 0;
            maxRow = 0;

            for (row = 0; row < mat.size(); row++)
            {
                maxRow = mat[row][midCol] > mat[maxRow][midCol] ? row : maxRow;
            }

            bool isrightBig = midCol + 1 <= endCol && mat[maxRow][midCol + 1] > mat[maxRow][midCol];
            bool isleftBig = midCol - 1 >= startCol && mat[maxRow][midCol - 1] > mat[maxRow][midCol];

            if (!isleftBig && !isrightBig)
                return vector<int>{maxRow, midCol};

            if (isrightBig)
                startCol = midCol + 1;
            else
                endCol = midCol - 1;
        }

        return vector<int>{-1, -1};
    }
};