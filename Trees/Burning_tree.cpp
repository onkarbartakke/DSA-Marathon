#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


void Traverse(Node *r, unordered_map<int, vector<int>> &mp)
{
    if (r == NULL)
        return;

    if (r->left)
    {
        mp[r->data].push_back(r->left->data);
        mp[r->left->data].push_back(r->data);
    }

    if (r->right)
    {
        mp[r->data].push_back(r->right->data);
        mp[r->right->data].push_back(r->data);
    }

    Traverse(r->left, mp);
    Traverse(r->right, mp);
}

int minTime(Node *root, int target)
{
    // Your code goes here

    unordered_map<int, vector<int>> mp;

    Traverse(root, mp);

    int count = 0;

    if (root == NULL)
        return 0;

    queue<int> qu;
    unordered_set<int> st;

    qu.push(target);
    st.insert(target);

    while (!qu.empty())
    {
        int sz = qu.size();
        bool change = false;
        while (sz--)
        {
            int b = qu.front();
            qu.pop();

            for (auto it : mp[b])
            {
                if (st.find(it) == st.end())
                {
                    change = true;
                    qu.push(it);
                    st.insert(it);
                }
            }
        }

        if (change)
            count++;
    }

    return count;
}

int main()
{
}