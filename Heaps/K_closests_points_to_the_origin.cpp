#include <bits/stdc++.h>

using namespace std;
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest
 points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        vector<vector<int>> ans;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;

        for (auto p : points)
        {
            int dist = p[0] * p[0] + p[1] * p[1];

            if (pq.size() < k)
            {
                pq.push({dist, {p[0], p[1]}});
            }
            else if (dist < pq.top().first)
            {
                pq.pop();
                pq.push({dist, {p[0], p[1]}});
            }
        }

        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};