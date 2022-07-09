#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool possible(vector<int> &nums, int mid, int k)
    {
        int j = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (j < nums.size() && nums[j] - nums[i] <= mid)
                j++;

            j--;

            count += (j - i);
        }

        return count >= k;
    }
    
    int smallestDistancePair(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0], mid;

        int ans;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (possible(nums, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};