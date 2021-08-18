#include <iostream>

using namespace std;

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr + n);
    int i, j, k;
    long long int ans = 0;
    for (i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;

        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] >= sum)
                k--;
            else
            {
                ans = ans + (k - j);
                j++;
            }
        }
    }

    return ans;
}

int main()
{
    
}