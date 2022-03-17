#include <bits/stdc++.h>

using namespace std;

/*
You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith 
engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.
*/

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {

        vector<pair<int, int>> ES(n);

        for (int i = 0; i < n; i++)
        {
            ES[i] = {efficiency[i], speed[i]};
        }

        sort(ES.rbegin(), ES.rend());

        long int sum = 0;
        long int res = 0;
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (auto p : ES)
        {
            int e = p.first;
            int s = p.second;

            minheap.push(s);

            if (minheap.size() > k)
            {
                int s1 = minheap.top();
                minheap.pop();

                sum = sum - s1;
            }

            sum += s;

            res = max(res, sum * e);
        }

        return res % (int)(1e9 + 7);
    }
};