#include <bits/stdc++.h>

using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
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
    int ans;
    class BST
    {
        public:
        bool bst;
        int curr_sum;
        int mini;
        int maxi;
        BST()
        {
            bst = true;
            curr_sum = 0;
            mini = INT_MAX;
            maxi = INT_MIN;
        }
    };

    BST calcSumBst(TreeNode *r)
    {
        if (r == NULL)
        {
            BST b = BST();
            return b;
        }

        BST left = calcSumBst(r->left);
        BST right = calcSumBst(r->right);
        BST b;
        if (left.bst && right.bst && r->val > left.maxi && r->val < right.mini)
        {
            b.bst = true;
            b.curr_sum = r->val + left.curr_sum + right.curr_sum;
            b.mini = min(r->val, min(left.mini, right.mini));
            b.maxi = max(r->val, max(left.maxi, right.maxi));
        }
        else
        {
            b.bst = false;
            b.curr_sum = max(left.curr_sum, right.curr_sum);
        }

        ans = max(ans, b.curr_sum);
        return b;
    }
    int maxSumBST(TreeNode *root)
    {
        ans = INT_MIN;

        calcSumBst(root);

        return ans > 0 ? ans : 0;
    }
};
int main()
{
}