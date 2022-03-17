#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        int usedRow[9][9] = {0}, usedCol[9][9] = {0}, usedBox[9][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int boxNum = (i / 3) * 3 + (j / 3);

                    if (usedRow[i][num] || usedCol[j][num] || usedBox[boxNum][num])
                        return false;

                    usedRow[i][num] = usedCol[j][num] = usedBox[boxNum][num] = 1;
                }
            }
        }

        return true;
    }
};

/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/