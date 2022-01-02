#include <bits/stdc++.h>

using namespace std;

/*

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 
 */
class Solution
{
    public:
    int strStr(string haystack, string needle)
    {

        if (needle == "")
            return 0;

        if (haystack == "")
            return -1;

        int n = needle.size();

        vector<int> lps(n, 0);

        int j;

        for (int i = 1; i < n; i++)
        {
            j = lps[i - 1];

            while (j > 0 && needle[i] != needle[j])
                j = lps[j - 1];

            if (needle[i] == needle[j])
                j++;

            lps[i] = j;
        }

        int i;

        i = 0;
        j = 0;

        while (i < haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;

                if (j >= needle.size())
                {
                    return i - needle.size();
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    j = 0;
                    i++;
                }
            }
        }

        return -1;
    }
};