#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, 
and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 
 */
class Solution
{
    public:
    // return 0 if it is unmonitored or leaf node
    // return 1 if it has cam or is parent of leaf node
    // return 2 if it is monitored without the cam on it's node

    int Traverse(TreeNode *r, int &ans)
    {
        if (r == NULL)
            return 2;

        if (r->left == NULL && r->right == NULL)
            return 0;

        int left = Traverse(r->left, ans);
        int right = Traverse(r->right, ans);

        if (left == 0 || right == 0)
        {
            ans++;
            return 1;
        }

        if (left == 1 || right == 1)
            return 2;
        else
            return 0;
    }
    int minCameraCover(TreeNode *root)
    {

        int ans = 0;
        int ret = Traverse(root, ans);

        if (ret == 0)
            ans++;

        return ans;
    }
};

/*
Consider a node in the tree.
It can be covered by its parent, itself, its two children.
Four options.

Consider the root of the tree.
It can be covered by left child, or right child, or itself.
Three options.

Consider one leaf of the tree.
It can be covered by its parent or by itself.
Two options.

If we set a camera at the leaf, the camera can cover the leaf and its parent.
If we set a camera at its parent, the camera can cover the leaf, its parent and its sibling.

We can see that the second plan is always better than the first.
Now we have only one option, set up camera to all leaves' parent.

Here is our greedy solution:

Set cameras on all leaves' parents, thenremove all covered nodes.
Repeat step 1 until all nodes are covered.
Explanation:
Apply a recusion function dfs.
Return 0 if it's a leaf.
Return 1 if it's a parent of a leaf, with a camera on this node.
Return 2 if it's coverd, without a camera on this node.

For each node,
if it has a child, which is leaf (node 0), then it needs camera.
if it has a child, which is the parent of a leaf (node 1), then it's covered.

If it needs camera, then res++ and we return 1.
If it's covered, we return 2.
Otherwise, we return 0
*/