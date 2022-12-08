#include <bits/stdc++.h>

using namespace std;
/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.
*/

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {

        int n;
        n = nums.size();

        vector<int> mini(n);
        mini[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            mini[i] = min(mini[i - 1], nums[i]);
        }

        stack<int> st;

        for (int j = n - 1; j >= 0; j--)
        {
            if (nums[j] > mini[j])
            {
                while (!st.empty() && st.top() <= mini[j])
                    st.pop();

                if (!st.empty() && st.top() < nums[j])
                    return true;
            }

            st.push(nums[j]);
        }

        return false;
    }
};

/*
Let s1 denote nums[i], s2 denote nums[j] and s3 denote nums[k]. Now, we want s1<s3<s2.
We will make a minimum prefix array (mini), to find the minimum element till index i. Why so? This will hold our candidates for s1. After this, we will traverse from the back of the array and each element will be our candidate for s2. Now if at index j (while traversing from behind), we find mini[j]<nums[j], we have established s1<s2. Now we have to check for a suitable s3.

How to find suitable candidates for s3? We will maintain a stack for all the elements to the right of index j. (For the rightmost element, it will be empty). We will pop elements till the top of the stack is less than or equal to mini[j], i.e., s3<=s1 because we want the opposite. Now, if the stack isn’t empty and the top of stack (s3) is less than nums[j] (s2), then we have our 132 pattern! Otherwise, we just push nums[j] to the stack and move to the left.

Time Complexity: O(n)
Space Complexity: O(n)

class Solution {
public:
    // We need s1<s3<s2
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int mini[n];
        //mini at any position will be our candidate for s1
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
            mini[i]=min(mini[i-1], nums[i]);
        stack<int> st;
        for(int j=n-1;j>=0;j--){ //nums[j] will be our candidate for s2
            if(nums[j]>mini[j]){ //s1<s2
                while(!st.empty() && st.top()<=mini[j]){ //discarding all elements right to s2 which are smaller than s1 as we need s3>s1
                    st.pop();
                }
                if(!st.empty() && st.top()<nums[j]) //now st.top() is our candidate for s3 and we have ensured s1<s3<s2
                    return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};
*/
