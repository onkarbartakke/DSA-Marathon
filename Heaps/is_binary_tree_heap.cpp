#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int count_nodes(Node *tree)
{
    if (tree == NULL)
        return 0;

    return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

bool isComplete(Node *tree, int index, int n)
{
    if (tree == NULL)
        return true;

    if (index >= n)
        return false;

    if (isComplete(tree->left, 2 * index + 1, n) && isComplete(tree->right, 2 * index + 2, n))
        return true;
    else
        return false;
}

bool isHeaptil(Node *tree)
{
    if (tree == NULL)
        return true;

    if (tree->left == NULL && tree->right == NULL)
        return true;

    if (tree->right == NULL)
    {
        if (tree->data >= tree->left->data)
            return true;
        else
            return false;
    }
    else if (tree->left == NULL)
    {
        return false;
    }
    else
    {
        if (tree->data >= tree->left->data && tree->data >= tree->right->data)
            return (isHeaptil(tree->left) && isHeaptil(tree->right));
        else
            return false;
    }
}
bool isHeap(struct Node *tree)
{
    // code here
    int n = count_nodes(tree);

    if (isComplete(tree, 0, n) && isHeaptil(tree))
        return true;
    else
        return false;
}

int main()
{
}