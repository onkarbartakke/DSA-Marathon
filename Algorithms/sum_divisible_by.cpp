#include <bits/stdc++.h>

using namespace std;
/*
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, 
we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
*/
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {

        for (int i = 0; i < time.size(); i++)
            time[i] %= 60;

        vector<int> hash(60, 0);

        for (int i = 0; i < time.size(); i++)
            hash[time[i]]++;

        int count = 0;

        int i = 1;

        while (i < 30)
        {
            count += (hash[i] * hash[60 - i]);
            i++;
        }

        count += (hash[0] * (hash[0] - 1)) / 2;

        count += (hash[30] * (hash[30] - 1)) / 2;

        return count;
    }
};