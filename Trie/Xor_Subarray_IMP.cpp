#include <bits/stdc++.h>

using namespace std;
/*
Given an array find out max XOR subarray

*/

class Trie
{
public:
    vector<Trie *> link;

    Trie()
    {
        link = vector<Trie *>(2, NULL);
    }
};

int getMax(Trie *r, int val)
{
    int ret = 0;

    for (int i = 31; i >= 0; i--)
    {
        int b = (val >> i) & 1;

        if (r->link[1 - b] != NULL)
        {
            ret += (1 << i);
            r = r->link[1 - b];
        }
        else
            r = r->link[b];
    }

    return ret;
}

void Insert(Trie *r, int val)
{
    for (int i = 31; i >= 0; i--)
    {
        int b = (val >> i) & 1;

        if (r->link[b] == NULL)
            r->link[b] = new Trie();

        r = r->link[b];
    }
}


class Solution
{
public:
    int maxSubarrayXOR(int N, int arr[])
    {
        // code here

        int currXor = arr[0];
        int ret = INT_MIN;
        Trie *root = new Trie();
        Insert(root, arr[0]);
        ret = max(ret, arr[0]);

        for (int i = 1; i < N; i++)
        {
            currXor ^= arr[i];
            ret = max(ret, currXor);

            int maxEndingWith = getMax(root, currXor);
            ret = max(ret, maxEndingWith);

            Insert(root, currXor);
        }

        return ret;
    }
};


int main()
{
}