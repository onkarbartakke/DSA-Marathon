#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/maximum-score-of-a-good-subarray/discuss/1517266/3-Similar-Questions-oror-Same-Concept-oror-NSL-NSR
//IMP
/*
The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. 
Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such 
that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.
*/
class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {

        nums.push_back(0);
        long int mod = 1e9 + 7;

        int n = nums.size();
        vector<long int> preSum(n, 0);

        preSum[0] = nums[0];

        for (int i = 1; i < n; i++)
            preSum[i] = preSum[i - 1] + nums[i];

        long int ret = 0;

        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                int minindex = st.top();
                st.pop();

                int leftindex = (st.empty() ? 0 : st.top() + 1);
                int rightindex = i - 1;

                long int val = (preSum[rightindex] - preSum[leftindex] + nums[leftindex]) * nums[minindex];

                //                 cout<<"\nVal is : "<<val<<"\nSubarray is : ";
                //                  for(int j = leftindex; j<=rightindex; j++)
                //                      cout<<nums[j]<<" ";

                // cout<<"\n";
                ret = max(ret, val);

                // if(st.empty())
                // {
                //     val = nums[minindex]*preSum[i-1];
                //     ret = max(val,ret);
                // }
            }

            int rightindex = i;
            int leftindex = (st.empty() ? 0 : (st.top() + 1));
            long int val = (preSum[rightindex] - preSum[leftindex] + nums[leftindex]) * nums[rightindex];
            // cout<<"\nVal is : "<<val<<"\nSubarray is : ";
            //      for(int j = leftindex; j<=rightindex; j++)
            //          cout<<nums[j]<<" ";

            // cout<<"\n";
            ret = max(ret, val);
            st.push(i);
        }

        ret %= mod;

        int retint = ret;
        return retint;
    }
};


// NSL -NSR approach
class Solution1
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        int m = 1000000007;
        vector<long long> nsr(n), nsl(n);
        //NSL
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        //NSR
        stack<int> tt;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!tt.empty() && nums[tt.top()] >= nums[i])
                tt.pop();
            nsr[i] = tt.empty() ? n : tt.top();
            tt.push(i);
        }
        vector<long long> pref(n, 0);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            int mn = nums[i];
            int l = nsl[i] + 1, r = nsr[i] - 1;
            long long sum = pref[r] - (l == 0 ? 0 : pref[l - 1]);
            long long prod = mn * sum;
            ans = max(ans, prod);
        }
        return ans % m;
    }
};