#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the num of Elements : ";
    int i, j, k, n;
    cin >> n;
    int a[n];

    cout << "Enter the n Elements : ";

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int LIS[n] = {1}, LDS[n] = {1};

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
    }

    for (i = n - 2; i >= 0; i--)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[i] > a[j])
            {
                LDS[i] = max(LDS[i], 1 + LDS[j]);
            }
        }
    }
    int ans = 1;
    for (i = 0; i < n; i++)
    {
        ans = max(ans, LIS[i] + LDS[i] - 1);
    }

    cout << ans;
}