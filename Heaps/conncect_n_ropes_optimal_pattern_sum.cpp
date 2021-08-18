#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    if (n == 1)
        return 0;

    if (n == 2)
        return (arr[0] + arr[1]);

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (auto i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long sum = 0;

    while (!pq.empty())
    {
        long long a = pq.top();
        pq.pop();

        if (pq.empty())
            return sum;

        long long b = pq.top();
        pq.pop();

        sum += (a + b);

        pq.push(a + b);
    }

    return sum;
}

int main()
{
}