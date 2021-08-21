#include <iostream>

#include <vector>
using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
};

int globalsum = 0;

int Pathsum(BinaryTree *root)
{
    if (root == NULL)
        return 0;

    int left = Pathsum(root->left);

    int right = Pathsum(root->right);

    globalsum = max(globalsum, max(max(left, right) + root->value, root->value));
    globalsum = max(globalsum, left + right + root->value);

    return max(max(left, right) + root->value, root->value);
}


int maxPathSum(BinaryTree tree)
{
    // Write your code here.
    if (tree.left == NULL && tree.right == NULL)
        return tree.value;

    globalsum = INT_MIN;

    int left = Pathsum(tree.left);
    int right = Pathsum(tree.right);

    globalsum = max(globalsum, max(max(left, right) + tree.value, tree.value));
    globalsum = max(globalsum, left + right + tree.value);
    return globalsum;
}

//in other words

int Max_sum_path(Node *p,int& result)
{
    if(!p)
    return 0;

    int left,right;
    left=Max_sum_path(p->lchild,result);
    right=Max_sum_path(p->rchild,result);

    int max_straight, max_case;
    max_straight=max( max(left,right)+p->data,p->data);
    max_case=max(max_straight, left+right+p->data);
    result=max(result,max_case);
    return max_straight;

}

int main()
{
}