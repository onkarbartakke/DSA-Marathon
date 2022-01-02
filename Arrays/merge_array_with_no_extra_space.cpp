#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int i, j;
    i = n - 1;
    j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            int t = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = t;
        }

        i--;
        j++;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
}