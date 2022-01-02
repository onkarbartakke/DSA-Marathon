#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution1
{
public:
    Node *connect(Node *root)
    {
        if (root && root->left != NULL)
        {
            root->left->next = root->right;
            connect(root->left);
            if (root->next != NULL)
                root->right->next = root->next->left;
            connect(root->right);
        }

        return root;
    }
};

class Solution2
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
            return NULL;

        queue<Node *> qu;
        qu.push(root);
        qu.push(NULL);

        while (!qu.empty())
        {
            while (qu.front() != NULL)
            {
                Node *n = qu.front();
                qu.pop();

                n->next = qu.front();

                if (n->left)
                    qu.push(n->left);

                if (n->right)
                    qu.push(n->right);
            }

            qu.pop();

            if (qu.empty())
                break;

            qu.push(NULL);
        }

        return root;
    }
};