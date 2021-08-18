#include<iostream>

using namespace std;

int FindMaxSum(int arr[], int n)
{
    // Your code here
    int i, j, op1, op2;

    int ans[n];
    ans[0] = arr[0];
    ans[1] = max(arr[0], arr[1]);

    for (i = 2; i < n; i++)
    {
        op1 = arr[i] + ans[i - 2];
        op2 = ans[i - 1];

        ans[i] = max(op1, op2);
    }

    return ans[n - 1];
}

int main()
{
    
}