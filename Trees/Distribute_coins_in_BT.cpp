#include <bits/stdc++.h>

using namespace std;

// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins.
// There are n coins in total
// throughout the whole tree.

// In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child,
// or from child to parent.

// Return the minimum number of moves required to make every node have exactly one coin.

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

class Solution
{
public:
    int PostOrder(TreeNode *r, int &moves)
    {
        if (r == NULL)
            return 0;

        int left = PostOrder(r->left, moves);
        int right = PostOrder(r->right, moves);

        moves += (abs(left) + abs(right));

        return r->val + left + right - 1;
    }
    int distributeCoins(TreeNode *root)
    {

        int moves = 0;

        PostOrder(root, moves);

        return moves;
    }
};