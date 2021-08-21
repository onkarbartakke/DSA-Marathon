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

//Approach 1
BinaryTree *pre = NULL;
void FixPrevPtr(BinaryTree *root)
{

    if (root != NULL)
    {
        FixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        FixPrevPtr(root->right);
    }
}

BinaryTree *FixNextPtr(BinaryTree *root)
{
    BinaryTree *nex;

    while (root && root->right != NULL)
        root = root->right;

    nex = NULL;
    while (root && root->left != NULL)
    {
        nex = root;
        root = root->left;
        root->right = nex;
    }

    return root;
}

BinaryTree *flattenBinaryTree(BinaryTree *root)
{
    // Write your code here.
    if (root == NULL)
        return root;
    pre = nullptr;
    FixPrevPtr(root);

    return FixNextPtr(root);
}

// 2nd Approach

BinaryTree *BT_to_DLL(BinaryTree *root)
{
    if (root == NULL)
        return root;

    if (root->left)
    {
        BinaryTree *Left = BT_to_DLL(root->left);

        //Inorder predecessor
        while (Left->right != NULL)
        {
            Left = Left->right;
        }

        Left->right = root;
        root->left = Left;
    }

    if (root->right)
    {
        BinaryTree *Right = BT_to_DLL(root->right);

        //Inoder Successor

        while (Right->left != NULL)
        {
            Right = Right->left;
        }

        Right->left = root;
        root->right = Right;
    }

    return root;
}
BinaryTree *flattenBinaryTree(BinaryTree *root)
{
    // Write your code here.
    if (root == NULL)
        return root;

    root = BT_to_DLL(root);

    while (root->left != NULL)
        root = root->left;

    return root;
}

int main()
{
}