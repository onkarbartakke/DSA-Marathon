#include<bits/stdc++.h>

using namespace std;


/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move 
are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix 
represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel 
through it.

*/

void traverse(vector<string> &ans, string s, int i, int j, vector<vector<int>> &m, int n)
{
    if (i < 0 || j < 0 || i >= n || j >= n || m[i][j] != 1)
    {
        return;
    }

    if (m[i][j] == 1 && i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }

    m[i][j] = -1;
    traverse(ans, s + "D", i + 1, j, m, n);
    traverse(ans, s + "R", i, j + 1, m, n);
    traverse(ans, s + "U", i - 1, j, m, n);
    traverse(ans, s + "L", i, j - 1, m, n);
    m[i][j] = 1;
    return;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    string s = "";

    traverse(ans, s, 0, 0, m, n);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

}