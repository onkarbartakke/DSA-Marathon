#include <bits/stdc++.h>

using namespace std;

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{

    unordered_map<long int, long int> left;
    unordered_map<long int, long int> right;

    for (auto it : arr)
    {
        right[it]++;
    }

    long int count = 0;

    for (auto it : arr)
    {
        // if(left.find(it)!=left.end() && left[it]>0)
        // left[it]--;

        if (right.find(it) != right.end() && right[it] > 0)
            right[it]--;

        if (it % r == 0 && left.find(it / r) != left.end() && left[it / r] > 0)
        {
            long int l = left[it / r];

            if (right.find(it * r) != right.end() && right[it * r] > 0)
            {
                long int ri = right[it * r];

                count += (l * ri);
            }
        }

        left[it]++;
    }

    return count;
}

int main()
{
    long int n, i, r;
    cin >> n >> r;

    vector<long int> v(n);

    for (i = 0; i < n; i++)
        cin >> v[i];

    long int count = countTriplets(v, r);
    cout << count;
}
