#include <bits/stdc++.h>

using namespace std;
long long BitwiseAndPairSum(vector<int> &A, int n)
{
    long long sum = 0;

    for (int i = 31; i >= 0; i--)
    {
        int k = 0;

        for (int j = 0; j < n; j++)
            if (A[j] & (1 << i))
                k++;

        sum += ((1 << i) * (k * (k - 1)) / 2);
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

    cout << BitwiseAndPairSum(A, n);
}