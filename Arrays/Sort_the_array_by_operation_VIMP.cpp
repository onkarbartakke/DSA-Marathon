#include <bits/stdc++.h>

using namespace std;
//Crux is to find Longest Consecutive increasing subsequence
int sortArray(int N, vector<int> A)
{
    // Write your code here.
    vector<int> LastOccur(N + 1, N + 1);
    vector<int> FirstOccur(N + 1, N + 1);

    for (int i = 0; i < N; i++)
    {
        LastOccur[A[i]] = i;
        FirstOccur[A[i]] = min(i, FirstOccur[A[i]]);
    }

    int last = N + 1, ls = 0, maxi = 0;
    int cntDist = 0;
    for (int i = N; i >= 1; i--)
    {
        if (LastOccur[i] < N + 1)  //If element exits
        {
            cntDist++;
            if (LastOccur[i] < last)
            {
                ls++;
                last = FirstOccur[i];
                maxi = max(maxi, ls);
            }
            else
            {
                ls = 1;
                last = FirstOccur[i];
            }
        }
    }

    return cntDist - maxi;
}

/*
Ninja is given an array ‘A’ of length ‘N’ consisting of positive integers. He can do an operation as many times as he wants. 
In one operation, he can select an integer ‘x’ and count all the occurrences of ‘x’ in the array ‘A’ and remove them. 
Then he will add all the removed integer ‘x’ either in the front or at the end of the array ‘A’. 
He wants to sort the array in non-decreasing order using the minimum number of operations.
For example:
Let’s say ‘A’ = [2, 1, 1, 2, 3, 1, 4, 3]. If we select ‘x’ = 1 and add all the ‘1’ in front then the updated array 
‘A’ = [1, 1, 1, 2, 2, 3, 4, 3]. If we select ‘x’ = 4 and add all the ‘4’ in end then the updated array 
‘A’ = [1, 1, 1, 2, 2, 3, 3, 4]. Hence the array become sorted in two operations.
Input Format-
First-line contains ‘T’, denoting the number of Test cases.
For each Test case:
The first line contains an integer, ‘N’, denoting the array's length.
The following line contains ‘N’ space-separated integers, denoting the array ‘A’ elements.  
Output Format-
For each test case, you have to print the minimum operations required to sort the array ‘A’  in non-decreasing order.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints -
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10^4
1 <= A[i] <= N  for 1<= i <= ‘N’

Time Limit: 1 sec
*/