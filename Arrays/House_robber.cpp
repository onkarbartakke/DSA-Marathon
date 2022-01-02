#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int rob(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];

        if (nums.size() == 0)
            return 0;

        int sum1 = nums[0], sum2 = max(nums[1], nums[0]);

        for (int i = 2; i < nums.size(); i++)
        {
            int op1 = nums[i] + sum1;
            int op2 = sum2;

            sum1 = sum2;
            sum2 = max(op1, op2);
        }

        return sum2;
    }
};