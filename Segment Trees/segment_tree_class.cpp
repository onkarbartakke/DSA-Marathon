#include <bits/stdc++.h>

using namespace std;

class SGTree
{
    public:
    vector<int> seg;

    SGTree(int n)
    {
        seg.resize(4 * n);
    }

    void Build(vector<int> &arr, int low, int high, int ind)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (high + low) / 2;

        Build(arr, low, mid, 2 * ind + 1);

        Build(arr, mid + 1, high, 2 * ind + 2);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        return;
    }

    int query(int ind, int l, int r, int low, int high)
    {
        if (low > r || high < l) // [l,r,low,high] or [low,high,l,r]
            return INT_MAX;

        if (low >= l && high <= r) // [l, low, high, r]
            return seg[ind];

        int mid = (low + high) >> 1;

        int left = query(2 * ind + 1, l, r, low, mid);
        int right = query(2 * ind + 2, l, r, mid + 1, high);

        return min(left, right);
    }

    void update(int ind, int i, int val, int low, int high)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid)
            update(2 * ind + 1, i, val, low, mid);
        else
            update(2 * ind + 2, i, val, mid + 1, high);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main()
{
}