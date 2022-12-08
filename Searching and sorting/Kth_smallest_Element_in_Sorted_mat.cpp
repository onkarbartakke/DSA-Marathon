#include <bits/stdc++.h>

using namespace std;
/*

Given an n x n matrix where each of the rows and columns is sorted in ascending order,
return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).
 */
class Solution
{
public:
    int countOfLess(int val, vector<vector<int>> &mat)
    {
        int n = mat.size();

        int col = n - 1;
        int cnt = 0;

        for (int rows = 0; rows < mat.size(); rows++)
        {
            while (col >= 0 && mat[rows][col] > val)
                col--;

            cnt += (col + 1);
        }

        return cnt;
    }


    int kthSmallest(vector<vector<int>> &matrix, int k)
    {

        int mini, maxi;
        int n = matrix.size();

        mini = matrix[0][0], maxi = matrix[n - 1][n - 1];

        int left = mini, right = maxi;
        int mid;
        int ans;

        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (countOfLess(mid, matrix) >= k)
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return ans;
    }
};