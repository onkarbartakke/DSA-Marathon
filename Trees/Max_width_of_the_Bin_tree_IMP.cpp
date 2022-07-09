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
 

/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

 
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        queue<pair<TreeNode *, int>> qu;

        qu.push({root, 0});

        long maxLen = 0;
        while (!qu.empty())
        {
            TreeNode *node = qu.front().first;
            long l = qu.front().second;
            long r = l;
            long sz = qu.size();

            while (sz--)
            {

                r = qu.front().second;
                node = qu.front().first;
                qu.pop();
                cout << r << "\n";
                if (node->left)
                    qu.push({node->left, r * 2 + 1});

                if (node->right)
                    qu.push({node->right, r * 2 + 2});
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;

        //         queue<pair<TreeNode*, int>> q;
        //         long maxWidth = 1, size, left, right;
        //         q.push( {root, 0} );

        //         while( q.empty() == false ){

        //             size = q.size(), left = q.front().second, right = q.back().second;
        //             maxWidth = max(maxWidth, (right-left)+1);

        //             while( size ){

        //                 auto p = q.front();
        //                 long idx = p.second;
        //                 cout<<id<<"\n";
        //                 q.pop();

        //                 if( p.first->left != NULL ) q.push( {p.first->left, idx*2+1 } );

        //                 if( p.first->right != NULL ) q.push( {p.first->right, idx*2+2 } );

        //                 size -= 1;
        //             }
        //         }

        //         return maxWidth;
    }
};