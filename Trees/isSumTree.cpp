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

int sum(Node *root, bool &b)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int left = 0, right = 0;

    if (root->left)
        left = sum(root->left, b);

    ///if(b==false)
    //return 0;

    if (root->right)
        right = sum(root->right, b);

    if (left + right != root->data)
        b = false;

    return (left + right + root->data);
}
bool isSumTree(Node *root)
{
    // Your code hereboo
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    bool b = true;
    int left = 0, right = 0;

    if (root->left)
        left = sum(root->left, b);

    ////if(b==false)
    //return b;

    if (root->right)
        right = sum(root->right, b);

    if (left + right != root->data)
        b = false;

    return b;
}

int main()
{
}