#include <iostream>
#include <vector>
#include <stack>

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

void Traverse(Node *r, int k, int &i, vector<int> &ans)
{
    if (i > k)
        return;

    if (r)
    {
        Traverse(r->right, k, i, ans);
        ans.push_back(r->data);
        i++;
        Traverse(r->left, k, i, ans);
    }
}
int kthLargest(Node *root, int K)
{
    //Your code here
    vector<int> ans;
    int i = 0;
    Traverse(root, K, i, ans);

    return ans[K - 1];
}

int main()
{
}