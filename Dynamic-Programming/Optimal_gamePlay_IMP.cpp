#include <bits/stdc++.h>

using namespace std;
/*
Two players X and Y are playing a game in which there are pots of gold arranged in a line, each containing some gold coins. 
They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has 
a higher number of coins at the end. The objective is to maximize the number of coins collected by X, assuming Y also plays optimally.

Return the maximum coins X could get while playing the game. Initially, X starts the game.
*/
int solve(vector<int> &A, int left, int right, vector<vector<int>> &dp)
{
    if (left == right)
        return dp[left][left] = A[left];
    if (left > right)
        return 0;

    if (dp[left][right] != -1)
        return dp[left][right];

    int option1 = A[left] + min(solve(A, left + 2, right, dp), solve(A, left + 1, right - 1, dp));
    int option2 = A[right] + min(solve(A, left, right - 2, dp), solve(A, left + 1, right - 1, dp));

    return dp[left][right] = max(option1, option2);
}


int maxCoins(vector<int> &A, int n)
{
    //Write your code here

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(A, 0, n - 1, dp);
}