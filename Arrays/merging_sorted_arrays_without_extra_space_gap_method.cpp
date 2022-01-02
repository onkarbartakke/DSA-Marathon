#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int nextGap(int m)
    {
        if (m <= 1)
            return 0;

        return (m / 2 + m % 2);
    }
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int i, j;

        int gap = nextGap(m + n);

        while (gap)
        {
            for (i = 0; i + gap < m; i++)
            {
                if (nums1[i] > nums1[i + gap])
                    swap(nums1[i], nums1[i + gap]);
            }

            for (j = 0; i < m && j < n; i++, j++)
            {
                if (nums1[i] > nums2[j])
                    swap(nums2[j], nums1[i]);
            }

            for (j = 0; j + gap < n; j++)
            {
                if (nums2[j] > nums2[j + gap])
                    swap(nums2[j], nums2[j + gap]);
            }

            gap = nextGap(gap);
        }

        for (i = m, j = 0; j < n; i++, j++)
        {
            nums1[i] = nums2[j];
        }
    }
};