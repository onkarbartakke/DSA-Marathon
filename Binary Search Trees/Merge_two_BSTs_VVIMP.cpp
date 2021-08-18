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

    Node(int d=0)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};


void inorder(Node *r, vector<int> &ans)
{
    if (r)
    {
        inorder(r->left, ans);
        ans.push_back(r->data);
        inorder(r->right, ans);
    }
}

vector<int> merge(Node *root1, Node *root2)
{
    //Your code here
    vector<int> ans;

    if (root1 == NULL && root2 == NULL)
        return ans;

    if (root1 == NULL)
    {
        inorder(root2, ans);
        return ans;
    }

    if (root2 == NULL)
    {
        inorder(root1, ans);
        return ans;
    }

    Node *curr1 = root1, *curr2 = root2;

    stack<Node *> st1;
    stack<Node *> st2;

    while (curr1 != NULL || curr2 != NULL || !st1.empty() || !st2.empty())
    {
        if (curr1 != NULL || curr2 != NULL)
        {
            if (curr1)
            {
                st1.push(curr1);
                curr1 = curr1->left;
            }

            if (curr2)
            {
                st2.push(curr2);
                curr2 = curr2->left;
            }
        }
        else
        {
            if (st1.empty())
            {
                while (!st2.empty())
                {
                    Node *p = st2.top();
                    st2.pop();
                    p->left = NULL;
                    inorder(p, ans);
                }

                return ans;
            }

            if (st2.empty())
            {
                while (!st1.empty())
                {
                    Node *p = st1.top();
                    st1.pop();
                    p->left = NULL;
                    inorder(p, ans);
                }

                return ans;
            }

            curr1 = st1.top();
            st1.pop();
            curr2 = st2.top();
            st2.pop();

            if (curr1->data < curr2->data)
            {
                st2.push(curr2);
                curr2 = NULL;
                ans.push_back(curr1->data);
                curr1 = curr1->right;
            }
            else
            {
                st1.push(curr1);
                curr1 = NULL;
                ans.push_back(curr2->data);
                curr2 = curr2->right;
            }
        }
    }

    return ans;
}

int main()
{
}