#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
A lazy tourist wants to visit as many interesting locations in a city as possible without going one step further
than necessary. Starting from his hotel, located in the north-west corner of city, he intends to take a walk
to the south-east corner of the city and then walk back. When walking to the south-east corner,
he will only walk east or south, and when walking back to the north-west corner, he will only walk north or west.
After studying the city map he realizes that the task is not so simple because some areas are blocked.
Therefore he has kindly asked you to write a program to solve his problem.

Given the city map (a 2D grid) where the interesting locations and blocked areas are marked,
determine the maximum number of interesting locations he can visit. Locations visited twice are only counted once.

Input
The first line in the input contains the number of test cases (at most 20). Then follow the cases.
Each case starts with a line containing two integers, W and H (2 ≤ W , H ≤ 100), the width and the height of the city map.
Then follow H lines, each containing a string with W characters with the following meaning:

. Walkable area
* Interesting location (also walkable area)
# Blocked area

You may assume that the upper-left corner (start and end point) and lower-right corner (turning point) are walkable,
and that a walkable path of length H + W − 2 exists between them.


Solution:

Don't consider 1 tourist but 2 tourist, 1 walking from top left to bottom right
and 1 from bottom right to top left


path of tourist 2 is now reversed 
*/
int dp[105][105][105];

int dx1[4] = {1, 1, 0, 0};
int dy1[4] = {0, 0, 1, 1};
int dx2[4] = {1, 0, 1, 0};
int dy2[4] = {0, 1, 0, 1};

int solve(int x1, int y1, int x2, int y2, vector<string> &c, int w, int h)
{
    if (x1 < 0 || y1 < 0 || x1 >= h || y1 >= w || x2 < 0 || y2 < 0 || x2 >= h || y2 >= w)
        return INT_MIN;

    if (c[x1][y1] == '#' || c[x2][y2] == '#')
        return INT_MIN;

    if (x1 == h - 1 && y1 == w - 1)
    {
        return c[x1][y1] == '*';
    }
    if (dp[x1][y1][x2] != -1)
        return dp[x1][y1][x2];

    int ret = INT_MIN;

    for (int i = 0; i < 4; i++)
    {
        ret = max(ret, solve(x1 + dx1[i], y1 + dy1[i], x2 + dx2[i], y2 + dy2[i], c, w, h));
    }

    if (c[x1][y1] == '*')
        ret++;

    if (c[x2][y2] == '*')
        ret++;

    if (x1 == x2 && y1 == y2 && c[x1][y1] == '*')
        ret--;

    return dp[x1][y1][x2] = ret;
}


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w, h;

        cin >> w >> h;

        vector<string> c(h);

        for (int i = 0; i < h; i++)
        {
            cin >> c[i];
        }

        memset(dp, -1, sizeof dp);
        cout << solve(0, 0, 0, 0, c, w, h);

        cout << "\n";
    }
}

