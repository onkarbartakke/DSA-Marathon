#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int i, j, l, h, n = nums.size(), sum = 0;

        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                l = j + 1;
                h = n - 1;
                sum = target - (nums[i] + nums[j]);

                while (l < h)
                {
                    if (sum == nums[l] + nums[h])
                    {
                        vector<int> v(4, 0);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[l];
                        v[3] = nums[h];

                        ans.push_back(v);

                        while (l < h && nums[l] == v[2])
                            l++;

                        while (l < h && nums[h] == v[3])
                            h--;
                    }
                    else if (sum < (nums[l] + nums[h]))
                    {
                        h--;
                    }
                    else
                    {
                        l++;
                    }
                }

                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }

            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }

        return ans;
    }
};
