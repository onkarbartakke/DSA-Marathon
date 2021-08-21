#include <iostream>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree
{
public:
    int value;
    int height;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

int m = 0;

int CalHeight(BinaryTree *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
    {
        root->height = 1;
        return 1;
    }

    if (root->height == 0)
    {
        int left = 0, right = 0;

        if (root->left)
            left = CalHeight(root->left);

        if (root->right)
            right = CalHeight(root->right);

        if (left > right)
            root->height = left + 1;
        else
            root->height = right + 1;
    }

    int path = 0;
    if (root->left)
        path += root->left->height;

    if (root->right)
        path += root->right->height;

    m = max(path, m);

    return root->height;
}

int binaryTreeDiameter(BinaryTree *tree)
{
    // Write your code here.
    if (tree == NULL)
        return 0;

    m = 0;
    tree->height = CalHeight(tree);

    return m;
}

int main()
{
}