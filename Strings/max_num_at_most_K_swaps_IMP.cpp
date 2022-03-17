#include <bits/stdc++.h>

using namespace std;
/*
Given a number K and string str of digits denoting a positive integer, 
build the largest number possible by performing swap operations on the digits of str at most K times.


*/
void findMax(int pos, int k, string &maxstr, string str)
{
    if (k <= 0)
        return;

    int n = str.length();
    char maxchar = str[pos];
    for (int i = pos + 1; i < n; i++)
    {
        if (str[i] > maxchar)
            maxchar = str[i];
    }

    if (maxchar != str[pos])
        k--;

    for (int i = n - 1; i >= pos; i--)
    {
        if (str[i] == maxchar)
        {
            swap(str[i], str[pos]);

            if (str.compare(maxstr) > 0)
                maxstr = str;

            findMax(pos + 1, k, maxstr, str);

            swap(str[i], str[pos]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.

    string maxstr = str;
    findMax(0, k, maxstr, str);

    return maxstr;
}