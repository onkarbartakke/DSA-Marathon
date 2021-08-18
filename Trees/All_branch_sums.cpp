#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// This is the class of the input root. Do not edit it.
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

vector<int> ans;

void branchsumsUntil(BinaryTree *root, int sum)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(sum);
        return;
    }

    if (root->left)
        branchsumsUntil(root->left, sum + root->left->value);

    if (root->right)
        branchsumsUntil(root->right, sum + root->right->value);
}
vector<int> branchSums(BinaryTree *root)
{
    // Write your code here.
    ans.clear();
    branchsumsUntil(root, root->value);
    return ans;
}

int main()
{
}
