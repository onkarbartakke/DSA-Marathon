#include <iostream>
#include <vector>

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

void Traverse(Node *root, int level, int *maxlevel, vector<int> &ans)
{
    if (root)
    {
        if (level > *maxlevel)
        {
            ans.push_back(root->data);
            *maxlevel = level;
        }

        Traverse(root->left, level + 1, maxlevel, ans);
        Traverse(root->right, level + 1, maxlevel, ans);
    }
}
vector<int> rightView(Node *root)
{
    // Your Code here
    vector<int> ans;

    int maxlevel = 0;

    Traverse(root, 1, &maxlevel, ans);

    return ans;
}

int main()
{
}