#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    string getSmallestString(int n, int k)
    {

        string ans = "";

        for (int i = 0; i < n; i++)
        {
            ans += "a";
        }

        k -= n;

        for (int i = n - 1; i >= 0; i--)
        {
            if (k == 0)
                break;

            if (k < 25)
            {
                ans[i] = (char)('a' + k);
                k == 0;
                break;
            }
            else
            {
                ans[i] = (char)('a' + 25);
                k = k - 25;
            }
        }

        return ans;
    }
};