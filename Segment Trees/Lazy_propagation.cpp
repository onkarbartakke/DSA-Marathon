#include <bits/stdc++.h>

using namespace std;

void Build(int ind, int low, int high, vector<int> &seg, vector<int> &arr)
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;

    Build(2 * ind + 1, low, mid, seg, arr);
    Build(2 * ind + 2, mid + 1, high, seg, arr);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int RangeSumQuery(int ind, int low, int high, vector<int> &seg, vector<int> &lazy, int l, int r)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];

        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    if (r < low || l > high)
        return 0;

    if (low >= l && high <= r)
        return seg[ind];

    int mid = (low + high) >> 1;

    return RangeSumQuery(2 * ind + 1, low, mid, seg, lazy, l, r) + RangeSumQuery(2 * ind + 2, mid + 1, high, seg, lazy, l, r);
}

void RangeUpdateQuery(int ind, int low, int high, vector<int> &seg, vector<int> &lazy, int l, int r, int val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] = (high - low + 1) * lazy[ind];

        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    if (r < low || l > high)
        return;

    if (low >= l && high <= r)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }

        return;
    }

    int mid = (low + high) >> 1;

    RangeUpdateQuery(2 * ind + 1, low, mid, seg, lazy, l, r, val);
    RangeUpdateQuery(2 * ind + 2, mid + 1, high, seg, lazy, l, r, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> arr(n);

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> seg(4 * n);
    vector<int> lazy(4 * n, 0);

    Build(0, 0, n - 1, seg, arr);

    cout << "\nEnter the Queries : ";
    int q;
    cin >> q;

    while (q--)
    {
        cout << "\nEnter the type and range : (T, L , R) ";
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1)
        {
            cout << RangeSumQuery(0, 0, n - 1, seg, lazy, l, r) << "\n";
        }
        else if (t == 2)
        {
            cout << "\nEnter the Val : ";
            int val;
            cin >> val;
            RangeUpdateQuery(0, 0, n - 1, seg, lazy, l, r, val);
        }
    }
}