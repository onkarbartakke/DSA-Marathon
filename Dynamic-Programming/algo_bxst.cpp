#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool mycomp(vector<int> &a, vector<int> &b)
{
    if (a[2] == b[2])
        return (a[0] * a[1] < b[0] * b[1]);

    return (a[2] < b[2]);
}

vector<vector<int>> diskStacking(vector<vector<int>> disks)
{
    // Write your code here.
    vector<vector<int>> ans;

    int n, i, j;
    n = disks.size();
    sort(disks.begin(), disks.end(), mycomp);

    vector<int> height(n);
    for (i = 0; i < n; i++)
        height[i] = disks[i][2];

    cout<<"\n";
    for(i=0;i<n;i++)
    cout<<height[i]<<" ";

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (disks[i][0] > disks[j][0] && disks[i][1] > disks[j][1] && height[i] < height[j] + disks[i][2])
                height[i] = height[j] + disks[i][2];
        }
    }

    int m = 0, idx;
    for (i = 0; i < n; i++)
    {
        if (m < height[i])
        {
            idx = i;
            m = height[i];
        }
    }

    int h = m;
    while (idx >= 0)
    {
        ans.push_back(disks[idx]);
        i = idx;
        h = h - disks[idx][2];

        while (i >= 0)
        {
            if (height[i] == h)
            {
                idx = i;
                break;
            }

            i--;
        }

        if (i < 0)
            break;
    }
    cout<<"\n";
    for(i=0;i<n;i++)
    cout<<height[i]<<" ";

    cout<<"\n\n";


    return ans;
}

int main()
{
    int n,i,j;
    n=6;
    vector<vector<int>>disks(n,vector<int>(3));

    for(i=0;i<n;i++)
    {
        cin>>disks[i][0]>>disks[i][1]>>disks[i][2];
    }

    vector<vector<int>>ans=diskStacking(disks);

    for(auto v : ans)
    {
        for(auto it : v)
        cout<<it<<" ";

        cout<<"\n";
    }
}