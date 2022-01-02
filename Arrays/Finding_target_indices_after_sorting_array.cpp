#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {

        //         sort(nums.begin(),nums.end());

        //         vector<int>ans;

        //         for(int i=0;i<nums.size();i++)
        //         {
        //             if(nums[i]==target)
        //                 ans.push_back(i);
        //         }

        //         return ans;

        vector<int> ans;

        int less_than = 0;
        int tgt_cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < target)
                less_than++;
            else if (nums[i] == target)
                tgt_cnt++;
        }

        int i = less_than;
        while (tgt_cnt)
        {
            ans.push_back(i);
            i++;
            tgt_cnt--;
        }

        return ans;
    }
};