// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getMinDiff(int a[], int n, int k)
    {
        // code here
        int i, j, res, maxi, mini;

        sort(a, a + n);
        res = a[n - 1] - a[0];

        for (i = 1; i <= n - 1; i++)
        {
            if (a[i] >= k)
            {
                maxi = max(a[i - 1] + k, a[n - 1] - k);
                mini = min(a[i] - k, a[0] + k);

                res = min(res, maxi - mini);
            }
        }

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends