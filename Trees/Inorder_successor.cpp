#include <iostream>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;
    BinaryTree *parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

BinaryTree *LeftOfRight(BinaryTree *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

BinaryTree *temp = NULL;

BinaryTree *findInOrderSuccessor(BinaryTree *root, BinaryTree *node, BinaryTree **succ)
{
    if (root == NULL)
        return root;

    if (root == node || (temp = findInOrderSuccessor(root->left, node, succ)) || (temp = findInOrderSuccessor(root->right, node, succ)))
    {
        if (temp)
        {
            if (root->left == temp)
            {
                (*succ) = root;
                return NULL;
            }
        }

        return root;
    }

    return NULL;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node)
{
    // Write your code here.
    if (tree == NULL)
        return tree;

    if (node->right)
    {
        return LeftOfRight(node->right);
    }

    BinaryTree *t = tree;

    while (t->right != NULL)
        t = t->right;

    if (t == node)
        return NULL;

    BinaryTree *succ = NULL;
    findInOrderSuccessor(tree, node, &succ);

    return succ;
}

// 2nd Approach By reverse Inorder

BinaryTree *temp;
void reverseInorder(BinaryTree *root, BinaryTree *node, BinaryTree **succ)
{
    if (root == NULL)
        return;

    reverseInorder(root->right, node, succ);

    if (root == node)
    {
        if (*succ == NULL)
            temp = NULL;
        else
            temp = (*succ);
    }

    (*succ) = root;

    reverseInorder(root->left, node, succ);
}

BinaryTree *findSuccessor2(BinaryTree *tree, BinaryTree *node)
{
    // Write your code here.
    if (tree == NULL)
        return tree;

    if (node->right)
    {
        return LeftOfRight(node->right);
    }

    BinaryTree *succ = NULL;
    temp = NULL;
    reverseInorder(tree, node, &succ);

    return temp;
}

int main()
{
}
