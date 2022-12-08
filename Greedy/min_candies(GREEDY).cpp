#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
int main()
{
    long int n, i, j;
    cin >> n;
    long int a[n], left[n] = {0}, right[n] = {0};

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    left[0] = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            left[i] = 1 + left[i - 1];
        else
            left[i] = 1;
    }

    right[n - 1] = 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            right[i] = 1 + right[i + 1];
        else
            right[i] = 1;
    }

    long int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + max(left[i], right[i]);
    }

    cout << sum;
}