#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public: 
    bool DFS(TreeNode* r, ListNode *h)
    {
        if(!h)
            return true;
        if(!r)
            return false;
        
        if(r->val!=h->val)
            return false;
        
        if(DFS(r->left,h->next) || DFS(r->right,h->next))
            return true;
        else
            return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(!head)
            return true;
        if(!root)
            return false;
        
        if(root->val == head->val && DFS(root,head))
            return true;
        
        if(isSubPath(head,root->left) || isSubPath(head,root->right))
            return true;
        else
            return false;
    }
};