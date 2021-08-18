#include <bits/stdc++.h>

using namespace std;

vector<int> max_of_subarrays(vector<int> &a, int n, int k)
{
    // your code here
    vector<int> ans;
    deque<int> dq;

    int i, j;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && a[dq.back()] < a[i])
        {

            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(a[dq.front()]);

    for (i = k; i < n; i++)
    {
        if (dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && a[dq.back()] < a[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        ans.push_back(a[dq.front()]);
    }

    return ans;
}

int main()
{
    int n, k,i;
    cout << "Enter the num of Elements : ";
    cin >> n;
    vector<int> a(n);
    cout << "\nEnter the Elements : \n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\nEnter the Window Size : ";
    cin >> k;

    vector<int> ans = max_of_subarrays(a, n, k);

    cout << "\n\n";

    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}