#include <bits/stdc++.h>

using namespace std;
/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is
moving from the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
*/

// Multiset Sol taking O(n*logK)
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {

        multiset<int> mst(nums.begin(), nums.begin() + k);

        auto midptr = next(mst.begin(), k / 2);

        vector<double> medians;

        for (int i = k;; i++)
        {
            double m = (double(*midptr) + double(*prev(midptr, 1 - k % 2))) / 2.0;
            medians.push_back(m);

            if (i == nums.size())
                break;

            mst.insert(nums[i]);

            if (nums[i] < (*midptr))
                midptr--;

            if (nums[i - k] <= (*midptr))
                midptr++;

            mst.erase(lower_bound(mst.begin(), mst.end(), nums[i - k]));
        }

        return medians;
    }
};

// Vector solution taking O(n*k)

class Solution1
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {

        vector<double> res;
        vector<long long> med;

        for (int i = 0; i < k; i++)
            med.insert(lower_bound(med.begin(), med.end(), nums[i]), nums[i]);
        if (k % 2 == 0)
            res.push_back((double)(med[k / 2] + med[k / 2 - 1]) / 2);
        else
            res.push_back((double)med[k / 2]);

        for (int i = k; i < nums.size(); i++)
        {
            med.erase(lower_bound(med.begin(), med.end(), nums[i - k]));
            med.insert(lower_bound(med.begin(), med.end(), nums[i]), nums[i]);
            if (k % 2 == 0)
                res.push_back((double)(med[k / 2] + med[k / 2 - 1]) / 2);
            else
                res.push_back((double)med[k / 2]);
        }
        return res;
    }
};
+
// Using 2 Heaps
class Solution3
{
public:
    vector<double> ans;
    unordered_map<int, int> m;                           // to store the elements to be discarded
    priority_queue<int> maxh;                            // max heap for lower half
    priority_queue<int, vector<int>, greater<int>> minh; // min heap for upper half

    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            maxh.push(nums[i]);
        }
        for (int i = k / 2; i > 0; i--)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        for (int i = k; i < n; i++)
        {
            if (k % 2 == 0)
            {
                ans.push_back(((double)maxh.top() + (double)minh.top()) / 2.0);
            }
            else
            {
                ans.push_back(maxh.top() * 1.0);
            }
            int p = nums[i - k];
            int q = nums[i];
            int balance = 0;

            // discarding p if it's at the top, otherwise storing it in map
            if (p <= maxh.top())
            {
                balance--;
                if (p == maxh.top())
                {
                    maxh.pop();
                }
                else
                {
                    m[p]++;
                }
            }
            else
            {
                balance++;
                if (p == minh.top())
                {
                    minh.pop();
                }
                else
                {
                    m[p]++;
                }
            }

            // balancing, if needed

            if (!maxh.empty() && q <= maxh.top())
            {
                balance++;
                maxh.push(q);
            }
            else
            {
                balance--;
                minh.push(q);
            }

            if (balance < 0)
            {
                maxh.push(minh.top());
                minh.pop();
            }
            else if (balance > 0)
            {
                minh.push(maxh.top());
                maxh.pop();
            }

            // popping off the top if it's present in the map

            while (!maxh.empty() && m[maxh.top()])
            {
                m[maxh.top()]--;
                maxh.pop();
            }

            while (!minh.empty() && m[minh.top()])
            {
                m[minh.top()]--;
                minh.pop();
            }
        }
        if (k % 2 == 0)
        {
            ans.push_back(((double)maxh.top() + (double)minh.top()) / 2.0);
        }
        else
        {
            ans.push_back(maxh.top() * 1.0);
        }
        return ans;
    }
};

/*
We can maintain a balance variable for that which would be set to zero initially. This balance just makes sure if the difference in the number of elements in both the heaps before and after the window slides remains 0 or 1. If the elements to be discarded are at the top of both the heaps, we will pop them off immediately otherwise we will push elements that need to be discarded in a map. Then, we can push the new element (which is to the right) into the max-heap or min-heap depending on its value compared to the top of the heaps. If a number gets discarded from any heap and then a new number gets added to the same heap, the net balance remains zero. This indicates we don’t need any rebalancing. If needed, we can rebalance the heaps to maintain the lower half and upper half. After rebalancing, if the elements to be discarded are at the top of the heap, we pop them off and move our sliding window to the right.

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/