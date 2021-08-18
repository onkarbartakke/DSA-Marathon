#include <iostream>

using namespace std;

int search_FixedPoint(int a[], int n)
{
    int i, j, low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        if (a[low] == low)
            return low;

        if (a[high] == high)
            return high;

        mid = (low + high) / 2;
        if (a[mid] == mid)
            return mid;

        if (low < a[low] && mid < a[mid])
        {
            low = mid + 1;
        }
        else if (low < a[low] && mid > a[mid])
        {
            high = mid - 1;
        }
        else if (low > a[low] && mid > a[mid])
        {
            low = mid + 1;
        }
        else if (low > a[low] && mid < a[mid])
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n, i;
    cout << "Enter the Num of Elements : ";
    cin >> n;
    int a[n];
    cout << "\nEnter th Num of Elements : \n";

    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nFixed Point is " << search_FixedPoint(a, n);
}