#include <bits/stdc++.h>

using namespace std;

/*

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. 
If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

*/
class Solution
{
    public:
    int RabinKarp(string src, string target)
    {
        long long targetCode, hashCode, Base, power, mod, count;

        mod = 1e9 + 7;
        Base = 29;

        power = 1;
        int n, m;
        n = src.size();
        m = target.size();

        for (int i = 0; i < m; i++)
        {
            power = (power * Base) % mod;
        }

        targetCode = 0;
        hashCode = 0;

        for (int i = 0; i < m; i++)
        {
            targetCode = (((targetCode * Base) % mod) + (target[i] - 'a' + 1)) % mod;
        }

        for (int i = 0; i < n; i++)
        {
            hashCode = (((hashCode * Base) % mod) + (src[i] - 'a' + 1)) % mod;

            if (i < m - 1)
                continue;
            if (i >= m)
                hashCode = (hashCode - ((src[i - m] - 'a' + 1) * power) % mod) % mod;

            if (hashCode < 0)
                hashCode += mod;

            if (hashCode == targetCode)
            {
                if (src.substr(i - m + 1, m) == target)
                    return i - m + 1;
            }
        }

        return -1;
    }

    
    int repeatedStringMatch(string a, string b)
    {

        string src = a;
        string target = b;

        if (b == "")
            return 0;

        if (a == "" && b != "")
            return -1;

        int count = 1;
        while (a.size() < b.size())
        {
            a += src;
            count++;
        }

        if (RabinKarp(a, b) != -1)
        {
            cout << a << "\n";
            cout << b << "\n";

            return count;
        }

        if (RabinKarp(a + src, b) != -1)
        {
            cout << a + src << "\n";
            cout << b << "\n";
            return count + 1;
        }

        return -1;
    }
};