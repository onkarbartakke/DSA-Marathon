#include <bits/stdc++.h>

using namespace std;
/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

 
*/
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {

        long long mod = 1e9 + 7;

        stack<int> st;

        int n = arr.size();
        long long int sum = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i]))
            {
                int j = st.top();
                st.pop();

                long long int right = i - j;

                long long int left;
                int prevTop = -1;
                if (!st.empty())
                    prevTop = st.top();

                left = j - prevTop;

                sum += (long long)((arr[j] * left * right) % mod);

                sum %= mod;
            }

            st.push(i);
        }

        return sum;
    }
};