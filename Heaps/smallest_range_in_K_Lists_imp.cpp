#include <iostream>
#include <climits>

using namespace std;

class Heap
{
    public:
    int size;
    pair<int, int> H[10001];

    Heap()
    {
        size = 0;
    }

    int ceil(int i, int k)
    {
        if (i % 2 == 0)
            return (i / 2);
        else
            return (i / 2 + 1);
    }

    void push(pair<int, int> p)
    {
        int i, child, parent;
        H[size] = p;
        size++;
        child = (size - 1);
        parent = ceil(child, 2) - 1;

        if (size == 1)
            return;
        else
        {
            while (parent >= 0 && H[child].first < H[parent].first)
            {
                pair<int, int> t = H[child];
                H[child] = H[parent];
                H[parent] = t;

                child = parent;

                parent = ceil(child, 2) - 1;
            }
        }
    }

    pair<int, int> top()
    {
        return H[0];
    }

    void Heapify(int i, int n)
    {
        int left, right, smallest = i;

        left = 2 * i + 1;
        right = 2 * i + 2;

        if (left < n && H[smallest].first > H[left].first)
            smallest = left;

        if (right < n && H[smallest].first > H[right].first)
            smallest = right;

        if (smallest != i)
        {
            pair<int, int> t = H[smallest];
            H[smallest] = H[i];
            H[i] = t;

            Heapify(smallest, n);
        }
    }

    void pop()
    {
        pair<int, int> p = H[size - 1];
        H[0] = p;
        size--;
        Heapify(0, size);
    }
};

pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
    //code here
    //priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >minheap;
    Heap minheap;

    //vector<int>idx(k,0)
    int idx[k] = {0};

    int maxi, mini;
    maxi = INT_MIN;
    int i;
    for (i = 0; i < k; i++)
    {
        minheap.push({arr[i][0], i});

        maxi = max(maxi, arr[i][0]);
    }

    int Range = INT_MAX;
    pair<int, int> p;
    pair<int, int> ans;
    bool flag = true;
    while (flag)
    {
        p = minheap.top();
        minheap.pop();

        mini = p.first;

        if (Range > (maxi - mini))
        {
            ans.first = mini;
            ans.second = maxi;

            Range = maxi - mini;
        }

        i = p.second;

        if (idx[i] + 1 < n)
        {
            maxi = max(arr[i][idx[i] + 1], maxi);
            minheap.push({arr[i][idx[i] + 1], i});
            idx[i]++;
        }
        else
        {
            flag = false;
            break;
        }
    }

    return ans;
}

int main()
{
}