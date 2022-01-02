#include <bits/stdc++.h>

using namespace std;
/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.
*/
class Solution
{
    public:
    bool canReach(vector<int> &arr, int start)
    {

        queue<int> qu;

        qu.push(start);
        int n = arr.size();

        while (!qu.empty())
        {
            int i = qu.front();
            qu.pop();

            if (arr[i] == 0)
                return true;

            int left = i - arr[i];
            int right = i + arr[i];

            arr[i] = -1;

            if (left >= 0 && arr[left] != -1)
            {
                if (arr[left] == 0)
                    return true;

                qu.push(left);
            }

            if (right < n && arr[right] != -1)
            {
                if (arr[right] == 0)
                    return true;

                qu.push(right);
            }
        }

        return false;
    }
};