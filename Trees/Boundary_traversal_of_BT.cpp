#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
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

void LeftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left)
    {
        ans.push_back(root->data);
        LeftBoundary(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        LeftBoundary(root->right, ans);
    }
}

void PrintLeaves(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    PrintLeaves(root->left, ans);
    PrintLeaves(root->right, ans);

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
}

void RightBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->right)
    {
        RightBoundary(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        RightBoundary(root->left, ans);
        ans.push_back(root->data);
    }
}

vector<int> printBoundary(Node *root)
{
    //Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    LeftBoundary(root->left, ans);

    PrintLeaves(root->left, ans);

    PrintLeaves(root->right, ans);

    RightBoundary(root->right, ans);

    return ans;
}

int main()
{

}