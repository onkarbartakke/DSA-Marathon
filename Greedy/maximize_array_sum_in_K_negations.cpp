#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

long long int maximizeSum(long long int a[], int n, int k)
{
    // Your code goes here
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }

    while (k--)
    {
        long long t = pq.top();
        pq.pop();

        t = t * (-1);

        pq.push(t);
    }

    long long sum = 0;
    while (!pq.empty())
    {
        sum += (pq.top());

        pq.pop();
    }

    return sum;
}

int main()
{
}