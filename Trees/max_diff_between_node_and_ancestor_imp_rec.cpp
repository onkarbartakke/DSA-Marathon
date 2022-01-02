#include<bits/stdc++.h>

using namespace std;


//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and 
a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root , int mn = 100000, int mx = 0) {
        if(!root)
            return mx-mn;
        
        mx = max(mx,root->val);
        mn = min(mn,root->val);
        
        return max(maxAncestorDiff(root->left,mn,mx) , maxAncestorDiff(root->right,mn,mx));
    }
};