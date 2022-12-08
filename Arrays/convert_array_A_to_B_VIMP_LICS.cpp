#include <bits/stdc++.h>

using namespace std;

/*
Given two Arrays A[] and B[] of length N and M respectively. Find the minimum number of insertions and deletions on the 
array A[], 
required to make both the arrays identical.
Note: Array B[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at end.


Trivial solution would be to use 2-D DP(simialar to https://leetcode.com/problems/edit-distance/) but since N could be upto 100K
 it will give TLE.
 First delete the nums in A which are not in B
Now we need to find LCS between A and B, and keep those elements in A and delete rest, and also add remaining numbers in 
B which don't occur in the LCS to make it equal to B
To find the LCS(longest common subsequence) with trivial 2-D DP will give TLE, but since B is already sorted, 
Longest increasing subsequence in A will be the LCS which can be found in O(N*LogN) 
time(similar to https://leetcode.com/problems/longest-increasing-subsequence/),
 Time: O(NlogN), Space: O(N)

*/

int LCIS(vector<int> &a)
{
    int n = a.size();

    vector<int> st;

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(st.begin(), st.end(), a[i]);

        if (it == st.end())
            st.push_back(a[i]);
        else
            (*it) = a[i];
    }

    return st.size();
}
int minInsAndDel(int A[], int B[], int N, int M)
{
    // code here

    unordered_set<int> st;

    vector<int> a;

    for (int i = 0; i < M; i++)
    {
        st.insert(B[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (st.find(A[i]) != st.end())
            a.push_back(A[i]);
    }

    return N + M - 2 * LCIS(a);
}