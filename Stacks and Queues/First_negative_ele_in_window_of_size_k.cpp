#include <bits/stdc++.h>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k)
{

    vector<long long> ans;
    deque<long long> dq;
    long long int i, j;

    for (i = 0; i < k; i++)
    {
        if (a[i] < 0)
            dq.push_back(i);
    }

    if (dq.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(a[dq.front()]);
    }

    for (i = k; i < n; i++)
    {
        if (a[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            if (dq.front() <= i - k)
            {
                dq.pop_front();
            }

            if (!dq.empty())
            {
                ans.push_back(a[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
        }
    }

    return ans;
}

int main()
{
}