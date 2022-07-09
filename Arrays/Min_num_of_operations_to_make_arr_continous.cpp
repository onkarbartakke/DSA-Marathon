#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &A)
    {
        int N = A.size(), ans = N, j = 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A)); // only keep unique elements
        int M = A.size();
        for (int i = 0; i < M; ++i)
        {
            while (j < M && A[j] < A[i] + N)
                ++j;                   // let `j` point to the first element that is out of range -- `>= A[i] + N`.
            ans = min(ans, N - j + i); // The length of this subarray is `j - i`. We need to replace `N - j + i` elements to make it continuous.
        }
        return ans;
    }
};

/*
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

INTUITION
Elements in the continuous array will be like:i, i+1, i+2, ..., i + arr.size()-1, for some integer i, 
because, max(arr) - min(arr) = i + arr.size() - 1 - i = arr.size()-1, which is provided.

Thus, we will maintain a sliding window of a.size() (e.g a[i] - a[j] + 1<= a.size(), 
the difference of a[i]-a[j]+1 will be our slide, which will never exceed a.size()), and count the number 
of unique elements present in the slide. (e.g i-j+1), Our answer will be the maximum of such window, because 
we can change the elements of the array excluding them (As they are already good to go), which results in N - max.
*/