#include <bits/stdc++.h>

using namespace std;
/*
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
*/
int minSwaps(vector<vector<int>> &grid)
{
    int n = grid.size();
    int ans = 0;
    vector<int> t; // vector to keep track of trailing zeroes

    //Step 1 : Find all trailing zeroes
    for (int i = 0; i < n; i++)
    {
        int zero = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j])
                break;
            zero++;
        }
        t.push_back(zero);
    }

    //Step 2 : Apply greedy method and solve problem row by row
    for (int i = 0; i < n; i++)
    {

        int curr = i;
        int req = n - 1 - i; // how many zeroes we want at this particular row

        // Step 4 : find nearest row which fullfill our zeroes requirement
        while (curr < n and t[curr] < req)
            curr++;

        // Step 5 : If we are not able to find any such rows --> return -1
        if (curr == n)
            return -1;

        // Step 6 : If we able to find such row then add cost to swap it
        ans += curr - i;

        // Step 7 : move all such rows 1 step ahead which are in b/w the source row and dest row
        while (curr > 0)
        {
            t[curr] = t[curr - 1];
            curr--;
        }
    }

    return ans;
}