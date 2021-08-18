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

int sumTree(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
    {
        int s = root->data;
        root->data = 0;

        return s;
    }

    int s = root->data;
    int left = sumTree(root->left);
    int right = sumTree(root->right);

    root->data = (left + right);

    return (s + root->data);
}
void toSumTree(Node *node)
{
    // Your code here
    int left = sumTree(node->left);

    int right = sumTree(node->right);

    node->data = (left + right);
}

int main()
{
    
}