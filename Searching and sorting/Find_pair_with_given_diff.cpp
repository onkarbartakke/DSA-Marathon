#include <iostream>
#include <algorithm>
using namespace std;

/*

Wrong Answer. !!!Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
116 265
3327 6546 9191 5756 3544 9033 2221 6794 1292 607 5685 160 5485 6104 844 2842 6313 4734 5040 6083 7795 9336 5941 5322 9319 4863 5905 4166 52 9372 7282 9730 2269 6473 5485 5813 1857 4057 2606 9501 4663 8290 9660 147 4394 504 9340 706 1589 4380 3141 5735 3715 9081 7408 9385 3943 3312 3550 346 9036 831 75 1304 3655 1911 7116 5512 2319 6073 1364 3333 715 1023 9831 5108 7878 9170 2165 5819 3549 1657 1553 3615 737 8961 2999 1031 8624 2900 7728 7659 83 4154 5315 3737 6064 8782 5600 4734 4855 696.................

Its Correct output is:
-1

And Your Code's output is:
1

*/

bool findPair(int arr[], int size, int n)
{
    //code

    sort(arr, arr + size);

    int i, j;
    i = 0;
    j = size - 1;
    int diff;
    for (i = 0; i < size; i++)
    {
        int l = i + 1;
        int h = size - 1;
        int mid;
        int ele = arr[i] + n;

        if (arr[h] < ele)
            continue;

        if (arr[l] > ele)
            continue;

        while (l <= h)
        {
            mid = (h + l) / 2;

            if (arr[mid] == ele)
                return true;

            if (arr[mid] < ele)
                l = mid + 1;

            if (arr[mid] > ele)
                h = mid - 1;
        }
    }

    return false;
}

int main()
{
    int n, i, j, diff;
    cin >> n;
    cin >> diff;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (findPair(arr, n, diff))
    {
        cout << "1\n";
    }
    else
    {
        cout << "-1\n";
    }
}