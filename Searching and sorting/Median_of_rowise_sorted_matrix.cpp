#include <bits/stdc++.h>

using namespace std;

int FindMedian(vector<vector<int>> &Mat)
{
    int r, c;
    r = Mat.size();
    c = Mat[0].size();

    int desired = (r * c) / 2;

    int mini = INT_MAX, maxi = INT_MIN;

    for (int i = 0; i < r; i++)
    {
        if (mini > Mat[i][0])
            mini = Mat[i][0];

        if (maxi < Mat[i][c - 1])
            maxi = Mat[i][c - 1];
    }

    int mid, count;
    while (mini < maxi)
    {
        mid = (maxi + mini) / 2;

        count = 0;
        for (int i = 0; i < r; i++)
        {
            count += (upper_bound(Mat[i].begin(), Mat[i].end(), mid) - Mat[i].begin());
        }

        if (count < desired)
            mini = mid + 1;
        else
            maxi = mid;
    }

    return mini;
}

int main()
{
}