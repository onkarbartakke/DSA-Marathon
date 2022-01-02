#include <bits/stdc++.h>

using namespace std;

void Build(vector<int> &arr, int low, int high, int ind, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (high + low) / 2;

    Build(arr, low, mid, 2 * ind + 1, seg);

    Build(arr, mid + 1, high, 2 * ind + 2, seg);

    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    return;
}

int query(int ind, int l, int r, vector<int> &seg, int low, int high)
{
    if (low > r || high < l) // [l,r,low,high] or [low,high,l,r]
        return INT_MAX;

    if (low >= l && high <= r) // [l, low, high, r]
        return seg[ind];

    int mid = (low + high) >> 1;

    int left = query(2 * ind + 1, l, r, seg, low, mid);
    int right = query(2 * ind + 2, l, r, seg, mid + 1, high);

    return min(left, right);
}

void update(int ind, int i, int val, vector<int> &seg, int low, int high)
{
    if (low == high)
    {
        seg[ind] = val;
        return;
    }

    int mid = (low + high) >> 1;

    if (i <= mid)
        update(2 * ind + 1, i, val, seg, low, mid);
    else
        update(2 * ind + 2, i, val, seg, mid+1, high);

    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int main()
{
    int n, i;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "\n\nEnter thr array elements : ";

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"\n\n";
    for(auto it : arr)
    cout<<it<<" ";
    vector<int> seg(4 * n, -1);

    Build(arr, 0, n - 1, 0, seg);

    cout<<"\nSegment Tree is : \n";

    for(auto it : seg)
    {
        if(it!=-1)
        cout<<it<<" ";
    }

    cout << "\n\nEnter the Number of queries : ";
    int q;
    cin >> q;

    while (q--)
    {
        cout << "\nEnter the Query : ";
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
        {
            cout << query(0, a, b, seg, 0, n - 1);
        }
        else if (type == 2)
        {
            update(0, a, b, seg, 0, n - 1);
            arr[a] = b;
        }
    }
}