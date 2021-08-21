#include <iostream>
#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value);
};

void mutate(BinaryTree *root, BinaryTree *parent, bool isLeftChild)
{
    if (root == NULL)
        return;

    BinaryTree *Left, *Right;
    Left = root->left;
    Right = root->right;

    mutate(Left, root, true);
    if (parent == NULL)
    {
        root->right = NULL;
    }
    else if (isLeftChild)
    {
        root->right = parent->right;
    }
    else
    {
        if (parent->right == NULL)
        {
            root->right = NULL;
        }
        else
        {
            root->right = parent->right->left;
        }
    }
    mutate(Right, root, false);
}

BinaryTree *rightSiblingTree(BinaryTree *root)
{
    // Write your code here.

    mutate(root, NULL, false);
    return root;
}

int main()
{
}


//other approach


