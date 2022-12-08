#include <bits/stdc++.h>

using namespace std;
/*
You are given a matrix of dimension n*n. All the cells are initially, zero. 
You are given Q queries, which contains 4 integers a b c d where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. Now, all the cells of this submatrix have to 
be incremented by one. After all the Q queries have been performed. Your task is to find the final resulting Matrix.
Note : Zero-Based Indexing is used for cells of the matrix. 
*/

vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries)
{
    // Code here

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (auto q : Queries)
    {
        int startRow = q[0], startCol = q[1];
        int endRow = q[2], endCol = q[3];

        for (int i = startRow; i <= endRow; i++)
        {
            grid[i][startCol]++;
        }

        if (endCol + 1 < n)
        {
            for (int i = startRow; i <= endRow; i++)
            {
                grid[i][endCol + 1]--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            grid[i][j] += grid[i][j - 1];
        }
    }

    return grid;
}