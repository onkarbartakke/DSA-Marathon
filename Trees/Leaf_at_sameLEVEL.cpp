#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d = 0)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool FindLeaves(Node *root, int curr, int maxleaf)
{
    if (root->left == NULL && root->right == NULL)
    {
        if (curr == maxleaf)
            return true;
        else
            return false;
    }

    bool left = true, right = true;
    if (root->left)
    {
        left = FindLeaves(root->left, curr + 1, maxleaf);
    }

    if (root->right)
    {
        right = FindLeaves(root->right, curr + 1, maxleaf);
    }

    return (right && left);
}

bool check(Node *root)
{
    //Your code here
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    bool b;

    Node *r = root;
    int leaflevel = 0;

    while (r->left != NULL || r->right != NULL)
    {
        if (r->left != NULL)
        {
            r = r->left;
            leaflevel++;
        }
        else
        {
            r = r->right;
            leaflevel++;
        }
    }

    return FindLeaves(root, 0, leaflevel);
}
int main()
{
}