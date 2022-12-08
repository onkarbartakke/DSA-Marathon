#include <bits/stdc++.h>

using namespace std;

int Kth_smallest(int *a1, int *a2, int *e1, int *e2, int k)
{
    if (a1 == e1)
        return *(a1);

    if (a2 == e2)
        return *(e2);

    int m1, m2;

    m1 = ((e1 - a1 + 1) / 2);
    m2 = ((e2 - a2 + 1) / 2);

    if (m1 + m2 < k)
    {
        if (a1[m1] > a2[m2])
        {
            return Kth_smallest(a1, a2 + m2, e1, e2, k - m2 - 1);
        }
        else
        {
            return Kth_smallest(a1 + m1, a2, e1, e2, k - m1 - 1);
        }
    }
    else
    {
        if (a1[m1] > a2[m2])
        {
            return Kth_smallest(a1, a2, e1 - m1, e2, k);
        }
        else
        {
            return Kth_smallest(a1, a2, e1, e2 - m2, k);
        }
    }
}
int main()
{
    int n, i, j, m;
    cout << "Enter the size of 1st Array : ";
    cin >> n;
    cout << "Enter the n elements in Sorted order : \n";
    int a1[n];
    for (i = 0; i < n; i++)
        cin >> a1[i];

    cout << "\nEnter the size of 2nd Array : ";
    cin >> m;
    int a2[m];
    cout << "\nEnter the m elements in sorted order : \n";
    for (i = 0; i < m; i++)
        cin >> a2[i];

    cout << "\nEnter thr val of K , to find Kth smallest element : ";
    int k;
    cin >> k;
    int *e1, *e2;
    e1 = a1 + n - 1;
    e2 = a2 + m - 1;
    cout << "\n**\n";
    cout << "\nKth smallest Element is " << Kth_smallest(a1, a2, e1, e2, k);
}

// Striver Approach

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m)
    {
        return kthElement(arr2, arr1, m, n, k);
    }

    int low = max(0, k - m), high = min(k, n);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
}

class Solution
{
public:
  
};