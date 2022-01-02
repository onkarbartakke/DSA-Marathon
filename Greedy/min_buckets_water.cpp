#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int minimumBuckets(string street)
    {

        int cnt = 0;
        int n = street.size();

        for (int i = 0; i < n;)
        {
            if (street[i] == 'H')
            {
                if (i + 1 < n && street[i + 1] == '.')
                {
                    cnt++;
                    i += 3;
                    continue;
                }
                else if (i - 1 >= 0 && street[i - 1] == '.')
                {
                    cnt++;
                    i++;
                    continue;
                }

                return -1;
            }

            i++;
        }

        return cnt;
    }
};