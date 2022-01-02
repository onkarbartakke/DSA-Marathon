#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int Merge(vector<int> &nums, int l, int m, int h)
    {
        vector<int> v;
        int count = 0;
        int i, j;
        i = l;
        j = m + 1;

        for (i = l; i <= m; i++)
        {
            while (j <= h && (long)nums[i] > (long)2 * (long)nums[j])
                j++;

            count += (j - (m + 1));
        }

        i = l;
        j = m + 1;
        while (i <= m && j <= h)
        {

            if (nums[i] <= nums[j])
            {
                v.push_back(nums[i]);
                i++;
            }
            else if (nums[i] > nums[j])
            {
                v.push_back(nums[j]);
                j++;
            }
        }

        while (i <= m)
        {
            v.push_back(nums[i]);
            i++;
        }

        while (j <= h)
        {
            v.push_back(nums[j]);
            j++;
        }

        int k = 0;
        i = l;
        k = 0;
        while (i <= h)
            nums[i++] = v[k++];

        return count;
    }
    int MergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int inv = MergeSort(nums, low, mid);
        inv += MergeSort(nums, mid + 1, high);
        inv += Merge(nums, low, mid, high);

        return inv;
    }
    int reversePairs(vector<int> &nums)
    {

        return MergeSort(nums, 0, nums.size() - 1);
    }
};