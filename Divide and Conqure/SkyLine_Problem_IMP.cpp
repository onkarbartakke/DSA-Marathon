#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {

        vector<pair<int, int>> coords;

        for (auto v : buildings)
        {
            coords.push_back({v[0], (-1) * v[2]});
            coords.push_back({v[1], v[2]});
        }

        sort(coords.begin(), coords.end());

        multiset<int> mt = {0};

        vector<vector<int>> skyline;
        int top = 0;
        for (auto p : coords)
        {
            int x = p.first;
            int y = p.second;

            // cout<<"\n {"<<x<<" , "<<y<<" }  ";
            if (y < 0)
                mt.insert(-1 * y); // It impiles that it is starting point
            else
                mt.erase(mt.find(y)); // Removing the ending point, if only did mt.erase(y) we will lose all the occurences of y

            int h = *(mt.rbegin());
            // cout<<"\n h now is : "<<h;
            if (top != h)
            {
                top = h;
                skyline.push_back({x, h});
            }
        }

        return skyline;
    }
};

//https://leetcode.com/problems/the-skyline-problem/discuss/61222/17-Line-O(n-log-n)-time-O(n)-space-C%2B%2B-Accepted-Easy-Solution-w-Explanations

// Approach
// https://www.youtube.com/watch?v=POUMNJou4vc