#include <bits/stdc++.h>
#define Msize 100000 + 7

using namespace std;
/*
9
4 2 1 4 3 4 5 8 15
3
*/

vector<int> seg(Msize, 0);

int query(int ind, int left, int right, int low, int high)
{
    cout << "Ind : " << ind << "\n";
    cout << "Left Right : " << left << " : " << right << "\n";
    cout << "low high : " << low << " : " << high << "\n\n";

    if (right < low || left > high)
        return INT_MIN;

    if (low >= left && high <= right)
        return seg[ind];

    int mid = low + (high - low) >> 1;

    int leftSide = query(2 * ind + 1, left, right, low, mid);
    int rightSide = query(2 * ind + 2, left, right, mid + 1, high);

    return max(leftSide, rightSide);
}

void update(int ind, int i, int val, int low, int high)
{
    if (low == high)
    {
        seg[ind] = max(seg[ind], val);
        return;
    }

    int mid = (low + high) >> 1;

    if (i <= mid)
        update(2 * ind + 1, i, val, low, mid);
    else
        update(2 * ind + 2, i, val, mid + 1, high);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int lengthOfLIS(vector<int> &nums, int k)
{

    // int n = nums.size();

    int ans = 0;

    // cout<<"n = "<<nums.size()<<"\n";

    for (auto number : nums)
    {
        cout << "Starting for " << number << "\n";
        int left = max(1, number - k);

        cout << "Left ran\n";
        int right = number - 1;
        cout << "Right ran\n";
        int lis = query(0, left, right, 0, Msize - 1);

        cout << "Got the LIS : " << lis + 1 << "\n";

        ans = max(ans, lis + 1);
        update(0, number, lis + 1, 0, Msize - 1);

        cout << "For " << number << " : " << lis + 1 << "\n";
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;

    cin >> k;

    cout << "\n\n"
         << lengthOfLIS(nums, k);
}