#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {

        //         int pIndx = 0, sIndx = 0, match = 0 , starIndx = -1;

        //         while(sIndx < s.length())
        //         {
        //             if(s[sIndx] == p[pIndx] || p[pIndx] == '?')
        //             {
        //                 sIndx++;
        //                 pIndx++;
        //             }
        //             else if(p[pIndx] == '*')
        //             {
        //                 starIndx = pIndx;
        //                 match = sIndx;
        //                 pIndx++;
        //             }
        //             else if(starIndx != -1)
        //             {
        //                 pIndx = starIndx + 1;
        //                 match++;
        //                 sIndx = match;
        //             }
        //             else
        //                 return false;
        //         }

        //         while(pIndx < p.length() && p[pIndx] == '*')
        //             pIndx++;

        //         return pIndx == p.length();

        int plen = p.length(), slen = s.length();

        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));

        dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j)
        {
            dp[0][j + 1] = true;
        }
        for (int i = 1; i <= slen; i++)
        {
            for (int j = 1; j <= plen; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[slen][plen];
    }
};