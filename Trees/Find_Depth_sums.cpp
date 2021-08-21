#include <iostream>

using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

int sum = 0;

void FindDepth(BinaryTree *root, int d)
{
    if (root == NULL)
        return;

    sum = sum + d;

    if (root->left)
        FindDepth(root->left, d + 1);

    if (root->right)
        FindDepth(root->right, d + 1);
}
int nodeDepths(BinaryTree *root)
{
    // Write your code here.
    sum = 0;

    FindDepth(root, 0);
    return sum;
}

int main()
{
}