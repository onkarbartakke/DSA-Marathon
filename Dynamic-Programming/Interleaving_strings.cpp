#include<bits/stdc++.h>

using namespace std;

/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.



Here is some explanation:

DP table represents if s3 is interleaving at (i+j)th position when s1 is at ith position, and s2 is at jth position. 
0th position means empty string.

So if both s1 and s2 is currently empty, s3 is empty too, and it is considered interleaving. If only s1 is empty, then 
if previous s2 position is interleaving and current s2 position char is equal to s3 current position char, it is considered 
interleaving. similar idea applies to when s2 is empty. when both s1 and s2 is not empty, then if we arrive i, j from i-1, j,
 then if i-1,j is already interleaving and i and current s3 position equal, it s interleaving. 
If we arrive i,j from i, j-1, then if i, j-1 is already interleaving and j and current s3 position equal. it is interleaving.
*/


class Solution
{
    public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.length()!=s1.length()+s2.length())
            return false;
        
        int m,n;
        m = s1.length();
        n = s2.length();
        
        bool tabel[m+1][n+1];
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0; j<=n;j++)
            {
                if(i==0 && j==0)
                    tabel[i][j] = true;
                else if(i==0)
                    tabel[i][j] = (tabel[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if(j==0)
                    tabel[i][j] = (tabel[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    tabel[i][j] = (tabel[i-1][j] && s1[i-1]==s3[i+j-1]) || (tabel[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        
        return tabel[m][n];
    }
};