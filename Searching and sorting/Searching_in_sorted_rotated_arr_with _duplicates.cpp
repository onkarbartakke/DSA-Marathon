#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        int low, high, mid;

        low = 0;
        high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target || nums[low] == target || nums[high] == target)
                return true;

            if (nums[low] == nums[mid] && nums[mid] == nums[high]) // Shrinking the space between
            {
                low++;
                high--;
            }
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && nums[mid] >= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};