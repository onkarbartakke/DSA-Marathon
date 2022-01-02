#include <bits/stdc++.h>

using namespace std;
/*
A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 
 */
class Solution
{
    public:
    int nthMagicalNumber(int n, int a, int b)
    {

        long long int low, high, mid, ans, mod;

        mod = 1e9 + 7;

        if (b < a)
            swap(a, b);

        low = a;
        high = (long long)a * (long long)n;

        long long int lcm = ((long long)a * (long long)b) / __gcd(a, b);

        long long int cnt;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            cnt = (mid / a + mid / b - mid / lcm);

            if (cnt >= n)
            {
                ans = mid % mod;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};