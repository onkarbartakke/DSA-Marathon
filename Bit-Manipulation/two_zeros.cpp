#include <bits/stdc++.h>

using namespace std;

int countInteresting(int l, int r)
{
    // Write your code here.
    int cnt = 0;
    for (int bits = 3; bits <= 31; bits++)
    {
        int largest = (1 << bits) - 1;

        for (int i = 0; i < bits - 1; i++)
        {
            for (int j = i + 1; j < bits - 1; j++)
            {
                int num = (largest) ^ (1 << i) ^ (1 << j);

                if (num >= l && num <= r)
                    cnt++;
            }
        }
    }

    return cnt;
}
/*
A number ‘X’ is interesting if the binary representation of ‘X’ (without leading zeroes) has exactly two zeroes.
You are given two positive integers, ‘L’ and ‘R’. Your task is to count the number of values ‘X’, such that ‘L’ ≤ ‘X’ ≤ ’R’ and ‘X’ is interesting (i.e., it has exactly two zeroes in its binary representation).
Example :
L = 2, R = 9
All the numbers between L and R and their binary representations are:
X = 2 => 10
X = 3 => 11
X = 4 => 100
X = 5 => 101
X = 6 => 110
X = 7 => 111
X = 8 => 1000
X = 9 => 1001
As 4 and 9 are the only numbers with two zeroes in their binary representations, hence the answer is 2.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then the test case follows.

The first line of each test case contains two space-separated integers, ‘L’ and ‘R’, denoting the range in which you have to find interesting integers.
Output Format :
For each test case, count the number of values ‘X’, such that ‘L’ ≤ ‘X’ ≤ ’R’ and ‘X’ has exactly two zeroes in its binary representation.

Output for each test case will be printed on a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 ≤ T ≤ 30
1 ≤ L ≤ R ≤ 10^9

Time limit: 1 sec
*/