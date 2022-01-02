#include <bits/stdc++.h>

using namespace std;

/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group 
is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character.
 To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251"
*/
class Solution
{
    public:
    string countAndSay(int n)
    {

        if (n == 0)
            return "";

        if (n == 1)
            return "1";

        string curr, res;

        res = "1";

        while (--n)
        {
            curr = "";

            for (int i = 0; i < res.size(); i++)
            {
                int count = 1;

                while (i + 1 < res.size() && res[i] == res[i + 1])
                {
                    count++;
                    i++;
                }

                curr += (to_string(count) + res[i]);
            }

            res = curr;
        }

        return res;
    }
};