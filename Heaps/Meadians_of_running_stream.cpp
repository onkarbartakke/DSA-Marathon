#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

void insert(int x)
{
    if (pqmax.size() == pqmin.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
        }
        else
        {
            if (x < pqmax.top())
            {
                pqmax.push(x);
            }
            else
            {
                pqmin.push(x);
            }
        }
    }
    else
    {
        if (pqmax.size() < pqmin.size())
        {
            if (x <= pqmax.top())
            {
                pqmax.push(x);
            }
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmin.push(x);
                pqmax.push(temp);
            }
        }
        else
        {
            if (x >= pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmax.push(x);
                pqmin.push(temp);
            }
        }
    }
}

double Find_median()
{
    if (pqmax.size() == pqmin.size())
    {
        return (pqmax.top() + pqmin.top()) / 2.0;
    }
    else if (pqmax.size() > pqmin.size())
        return pqmax.top();
    else
        return pqmin.top();
}

int main()
{
    int n, i, x;
    cout << "\nEnter the num of elements : ";
    cin >> n;
    cout << "\nEnter the Elements : \n";

    for (i = 0; i < n; i++)
    {
        cin >> x;
        insert(x);
        cout << Find_median() << "\n";
    }
}

// Another Approach

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder()
    {
    }
    void addNum(int num)
    {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};