#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumBeauty(vector<int> &flws, long long newFlowers, int target, int full, int partial)
    {

        sort(flws.begin(), flws.end(), greater<int>());

        int p1 = 0, p2 = flws.size() - 1;

        long long needed, sum;

        for (p1 = 0; p1 < flws.size(); p1++)
        {
            if (target - flws[p1] > newFlowers)
                break;

            newFlowers -= max(0, target - flws[p1]);
        }

        int sz = flws.size();
        if (p1 == flws.size())
        {
            return max((long long)full * (long long)sz, (long long)(sz - 1) * (long long)full + (flws.back() < target ? (long long)(target - 1) * (long long)partial : full));
        }

        long long minF = flws.back();
        sum = 0;
        long long res = 0;
        while (minF < target)
        {
            while (p2 >= p1 && flws[p2] <= minF)
            {
                sum += flws[p2];
                p2--;
            }

            long long needed = (sz - p2 - 1) * minF - sum;

            if (needed > newFlowers)
            {
                p1--;
                if (p1 < 0)
                    break;

                newFlowers += max(0, target - flws[p1]);
            }
            else
            {
                res = max(res, (long long)full * p1 + minF * partial);
                minF++;
            }
        }

        return res;
    }
};