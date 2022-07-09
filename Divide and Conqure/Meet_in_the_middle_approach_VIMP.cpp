#include <bits/stdc++.h>

using namespace std;

// C++ program to demonstrate working of Meet in the
// Middle algorithm for maximum subset sum problem.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll X[2000005], Y[2000005];

// Find all possible sum of elements of a[] and store
// in x[]
void calcsubarray(ll a[], ll x[], int n, int c)
{
    for (int i = 0; i < (1 << n); i++)
    {
        ll s = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                s += a[j + c];
        x[i] = s;
    }
}

// Returns the maximum possible sum less or equal to S
ll solveSubsetSum(ll a[], int n, ll S)
{
    // Compute all subset sums of first and second
    // halves
    calcsubarray(a, X, n / 2, 0);
    calcsubarray(a, Y, n - n / 2, n / 2);

    int size_X = 1 << (n / 2);
    int size_Y = 1 << (n - n / 2);

    // Sort Y (we need to do doing binary search in it)
    sort(Y, Y + size_Y);

    // To keep track of the maximum sum of a subset
    // such that the maximum sum is less than S
    ll max = 0;

    // Traverse all elements of X and do Binary Search
    // for a pair in Y with maximum sum less than S.
    for (int i = 0; i < size_X; i++)
    {
        if (X[i] <= S)
        {
            // lower_bound() returns the first address
            // which has value greater than or equal to
            // S-X[i].
            int p = lower_bound(Y, Y + size_Y, S - X[i]) - Y;

            // If S-X[i] was not in array Y then decrease
            // p by 1
            if (p == size_Y || Y[p] != (S - X[i]))
                p--;

            if ((Y[p] + X[i]) > max)
                max = Y[p] + X[i];
        }
    }
    return max;
}

// Driver code
int main()
{
    ll a[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    ll S = 10;
    printf("Largest value smaller than or equal to given "
           "sum is %lld\n",
           solveSubsetSum(a, n, S));
    return 0;
}

/*
Meet in the middle
Difficulty Level : Hard
Last Updated : 09 Sep, 2021
Given a set of n integers where n <= 40. Each of them is at most 1012,
 determine the maximum sum subset having sum less than or equal S where S <= 1018.


 A Brute Force approach to solve this problem would be find all possible subset sums of N integers and check 
 if it is less than or equal S and keep track of such a subset with maximum sum. The time complexity using this 
 approach would be O(2n) and n is at most 40. 240 will be quite large and hence we need to find more optimal approach.

Meet in the middle is a search technique which is used when the input is small but not as small that brute force can be used.
 Like divide and conquer it splits the problem into two, solves them individually and then merge them. 
 But we can’t apply meet in the middle like divide and conquer because we don’t have the same structure as the original problem.

Split the set of integers into 2 subsets say A and B. A having first n/2 integers and B having rest.
Find all possible subset sums of integers in set A and store in an array X. Similarly calculate all possible subset sums
 of integers in set B and store in array Y. Hence, Size of each of the array X and Y will be at most 2n/2.
Now merge these 2 subproblems. Find combinations from array X and Y such that their sum is less than or equal to S.
One way to do that is simply iterate over all elements of array Y for each element of array X to check the existence of such a
 combination. This will take O( (2n/2)2) which is equivalent to O(2n).
To make it less complex, first sort array Y and then iterate over each element of X and for each element x in X use binary 
search to find maximum element y in Y such that x + y <= S.
Binary search here helps in reducing complexity from 2nto 2n/2log(2n/2)which is equivalent to 2n/2n.
Thus our final running time is O(2n/2n).
*/