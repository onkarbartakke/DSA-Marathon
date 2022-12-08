
// Online IDE - Code Editor, Compiler, Interpreter

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int c = 0;
        while (n && m)
        {
            if (n > m)
            {
                c += 1;
                n /= 2;
            }
            else if (n < m)
            {
                c += 1;
                m /= 2
            }
            else
            {
                cout << c + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}

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
    TreeNode *reverseOddLevels(TreeNode *root)
    {

        queue<TreeNode *> qu;
        qu.push(root);
        qu.push(NULL);
        bool isOdd = false;

        stack<TreeNode *> st;
        queue<int> qu1;

        while (!qu.empty())
        {
            if (isOdd)
            {
                TreeNode *node = qu.front();
                qu.pop();

                if (node == NULL)
                {
                    qu.push(NULL);
                    isOdd = !isOdd;

                    while (!qu1.empty())
                    {
                        int val = qu1.front();
                        qu1.pop();

                        TreeNode *rev = st.top();
                        st.pop();

                        rev->val = val;
                    }
                }
                else
                {
                    st.push(node);
                    qu1.push(node->val);

                    if (node->left)
                        qu.push(node->left);

                    if (node->right)
                        qu.push(node->right);
                }
            }
            else
            {
                TreeNode *node = qu.front();
                qu.pop();
                if (node == NULL)
                {
                    qu.push(NULL);
                    isOdd = !isOdd;
                }
                else
                {
                    if (node->left)
                        qu.push(node->left);

                    if (node->right)
                        qu.push(node->right);
                }
            }
        }

        return root;
    }
};