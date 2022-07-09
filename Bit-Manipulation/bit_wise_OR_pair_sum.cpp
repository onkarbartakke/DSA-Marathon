#include <bits/stdc++.h>

using namespace std;

long long BitwiseORPairSum(vector<int> &A, int n)
{
    long long sum = 0;

    for (int i = 31; i >= 0; i--)
    {
        long long k1 = 0, k2 = 0;

        for (int j = 0; j < n; j++)
        {
            if (A[j] & (1 << i))
                k1++;
            else
                k2++;

            sum += ((1 << i) * k1 * k2 + ((1 << i) * (k1) * (k1 - 1)) / 2);
        }
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << BitwiseORPairSum(A, n);
}