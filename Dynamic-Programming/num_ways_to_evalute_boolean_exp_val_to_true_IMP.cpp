#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define mod 1000000007

int solve(int i, int j, vector<vector<vector<ll>>> &dp, string &exp, int isTrue)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll ways = 0;
    for (int ind = i + 1; ind < j; ind = ind + 2)
    {
        ll lT = solve(i, ind - 1, dp, exp, 1);
        ll lF = solve(i, ind - 1, dp, exp, 0);
        ll rT = solve(ind + 1, j, dp, exp, 1);
        ll rF = solve(ind + 1, j, dp, exp, 0);

        if (exp[ind] == '&')
        {
            if (isTrue)
            {
                ways = (ways + (rT * lT) % mod) % mod;
            }
            else
            {
                ways = (ways + (rT * lF) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            }
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else
            {
                ways = (ways + (lF * rF) % mod) % mod;
            }
        }
        else if (exp[ind] == '^')
        {
            if (isTrue)
            {
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else
            {
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
            }
        }
    }

    return dp[i][j][isTrue] = ways % mod;
}

int evaluateExp(string &exp)
{
    // Write your code here.
    int n = exp.length();

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));

    return solve(0, n - 1, dp, exp, 1);
}

/*
You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and operators will be : (AND, OR, XOR). Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
Note :
‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
For example :
 Input:
 'EXP’ = T|T & F
 There are total 2  ways to parenthesize this expression:
 (i) (T | T) & (F) = F
 (ii) (T) | (T & F) = T
 Out of 2 ways, one will result in True, so we will return 1.

 Output :
 1
Note :
As the answer can be very large, return the output modulo 1000000007.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The second line of each test case contains a string representing the expression ‘EXP’.
Output format:
For each test case, print a single integer representing the number of ways we can parenthesize the expression such that it evaluates to true.

Print the output of each test case in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
3 <= |‘EXP’| <= 200
Where |EXP| denotes the length of 'EXP'.

Time Limit: 1 sec
**/