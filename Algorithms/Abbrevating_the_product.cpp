#include <bits/stdc++.h>

using namespace std;
/*

You are given two positive integers left and right with left <= right. Calculate the product of all integers in the inclusive range 
[left, right].

Since the product may be very large, you will abbreviate it following these steps:

Count all trailing zeros in the product and remove them. Let us denote this count as C.
For example, there are 3 trailing zeros in 1000, and there are 0 trailing zeros in 546.
Denote the remaining number of digits in the product as d. If d > 10, then express the product as <pre>...<suf> where 
<pre> denotes the first 5 digits of the product, and <suf> denotes the last 5 digits of the product after removing all trailing zeros. 
If d <= 10, we keep it unchanged.
For example, we express 1234567654321 as 12345...54321, but 1234567 is represented as 1234567.
Finally, represent the product as a string "<pre>...<suf>eC".
For example, 12345678987600000 will be represented as "12345...89876e5".
Return a string denoting the abbreviated product of all integers in the inclusive range [left, right].

*/
class Solution
{
    public:
    string abbreviateProduct(int left, int right)
    {

        long long suf = 1, max_suf = 10000000000, c = 0;
        bool over = false;
        double pref = 1.0;
        for (int i = left; i <= right; i++)
        {
            pref *= i;
            suf *= i;

            while (pref >= 100000)
            {
                pref /= 10;
            }

            while (suf % 10 == 0)
            {
                suf /= 10;
                c++;
            }

            over = over | suf >= max_suf;
            suf = suf % max_suf;
        }

        string s = to_string(suf);

        return (!over ? s : to_string((int)pref) + "..." + s.substr(s.size() - 5)) + "e" + to_string(c);
    }
};