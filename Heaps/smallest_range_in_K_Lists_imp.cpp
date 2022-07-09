#include <bits/stdc++.h>

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
    // code here
    // priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >minheap;
    Heap minheap;

    // vector<int>idx(k,0)
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

// Leetcode Approach

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            minheap.push({nums[i][0], i});
            maxi = max(maxi, nums[i][0]);
        }

        int n = nums.size();
        vector<int> idx(n, 0);

        long range = INT_MAX;
        pair<int, int> p, ans;

        bool flag = true;
        while (flag)
        {
            p = minheap.top();
            minheap.pop();

            mini = p.first;
            int i = p.second;
            // cout<<mini<<" --\n";
            if (range > (maxi - mini))
            {
                range = maxi - mini;
                ans.first = mini;
                ans.second = maxi;

                //  cout<<mini<<" "<<maxi<<"\n";
            }

            if (idx[i] + 1 < nums[i].size())
            {
                idx[i]++;

                maxi = max(maxi, nums[i][idx[i]]);
                minheap.push({nums[i][idx[i]], i});
            }
            else
            {
                flag = false;
                break;
            }
        }

        vector<int> a(2);
        a[0] = ans.first;
        a[1] = ans.second;

        return a;
    }
};

// Also Possible by sliding window

/*
Firstly we merge k groups to one group, each number recoard it's group, eg:

[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]

after merged we got：
[(0, 1), (4, 0), (5, 2), (9, 1), (10, 0), (12, 1), (15, 0), (18, 2), (20, 1), (22, 2), (24, 0), (26, 0), (30, 2)]

and see only group, it's
[1, 0, 2, 1, 0, 1, 0, 2, 1, 2, 0, 0, 2]

we can slide window by group when current groups satifies condition and recoard min range.

[1 0 2] 2 1 0 1 0 2 1 2 0 0 2    [0, 5]
1 [0 2 1] 1 0 1 0 2 1 2 0 0 2    [0, 5]
1 0 [2 1 0] 0 1 0 2 1 2 0 0 2    [0, 5]
1 0 [2 1 0 1] 1 0 2 1 2 0 0 2    [0, 5]
1 0 [2 1 0 1 0] 0 2 1 2 0 0 2    [0, 5]
1 0 2 1 0 [1 0 2] 2 1 2 0 0 2    [0, 5]
1 0 2 1 0 1 [0 2 1] 1 2 0 0 2    [0, 5]
1 0 2 1 0 1 [0 2 1 2] 2 0 0 2    [0, 5]
1 0 2 1 0 1 0 2 [1 2 0] 0 0 2    [20, 24]
1 0 2 1 0 1 0 2 [1 2 0 0] 0 2    [20, 24]
1 0 2 1 0 1 0 2 [1 2 0 0 2] 2    [20, 24]
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered; // (number, group)
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for (size_t j = 0; j < ordered.size(); ++j) {
            if (! count[ordered[j].second]++) ++k;
            if (k == nums.size()) {
                while (count[ordered[i].second] > 1) --count[ordered[i++].second]; // minialize range
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }

        return ans;
    }
};
*/

int main()
{
}