#include <bits/stdc++.h>

using namespace std;
/*
Given K sorted lists of integers, KSortedArray[] of size N each. 
The task is to find the smallest range that includes at least one element from each of the K lists. 
If more than one such range's are found, return the first such range found.


*/
pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
{
    //code here

    vector<int> idx(k, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hp;

    int Range, mini, maxi;

    Range = INT_MAX;

    maxi = KSortedArray[0][0];

    pair<int, int> ans;
    pair<int, int> t;

    for (int i = 0; i < k; i++)
    {
        hp.push({KSortedArray[i][0], i});
        maxi = max(maxi, KSortedArray[i][0]);
    }
    int i;
    while (!hp.empty())
    {
        t = hp.top();
        hp.pop();

        mini = t.first;
        i = t.second;

        if (Range > maxi - mini)
        {
            ans.first = mini;
            ans.second = maxi;

            Range = maxi - mini;
        }

        if (idx[i] + 1 < n)
        {
            idx[i]++;

            maxi = max(maxi, KSortedArray[i][idx[i]]);
            hp.push({KSortedArray[i][idx[i]], i});
        }
        else
            break;
    }

    return ans;
}