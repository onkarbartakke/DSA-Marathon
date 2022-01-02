#include <bits/stdc++.h>

using namespace std;

/*
Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where 
fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in 
ascending order, and each positioni is unique.

You are also given an integer startPos and an integer k. Initially, you are at the position startPos. 
From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at 
most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from 
that position.
*/


class Solution
{
    public:
    bool isValid(int startPos, int k, int left, int right)
    {
        if (right <= startPos)
            return startPos - left <= k;
        else if (left >= startPos)
            return right - startPos <= k;
        else
        {
            int x = startPos - left;
            int y = right - startPos;

            if (min(2 * x + y, 2 * y + x) <= k)
                return true;
            else
                return false;
        }
    }

    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {

        int left, right, maxi, n;

        left = 0;
        right = 0;
        maxi = 0;
        n = fruits.size();
        int sum = 0;
        while (right < n)
        {
            sum += fruits[right][1];

            while (left <= right && !isValid(startPos, k, fruits[left][0], fruits[right][0]))
            {
                sum -= fruits[left][1];

                left++;
            }

            maxi = max(maxi, sum);
            right++;
        }

        return maxi;
    }
};

/* Another approach is by using prefix sum to calculate in given range, that uses extra space as prefix sum array */