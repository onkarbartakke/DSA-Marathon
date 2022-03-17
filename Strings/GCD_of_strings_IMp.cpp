#include <bits/stdc++.h>

using namespace std;
/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {

        if (str1 + str2 != str2 + str1)
            return "";

        int l1 = str1.length();
        int l2 = str2.length();

        int g = __gcd(l1, l2);

        return str1.substr(0, g);
    }

    //Approach 2
    string gcdOfStrings1(string str1, string str2)
    {

        if (str1.size() < str2.size())
            return gcdOfStrings(str2, str1);
        if (str2.empty())
            return str1;
        if (str1.substr(0, str2.size()) != str2)
            return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};