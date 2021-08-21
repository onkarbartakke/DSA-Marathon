#include <iostream>
#include <vector>
#include<queue>
#include<stack>
#include<algorithm>
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

vector<int> topView(Node *root)
{
    Node *p;
    int hd = 0, rightMax = 0, leftMin = 0;

    queue<pair<Node *, int>> qu;

    qu.push({root, 0});
    vector<int> Right;
    stack<int> Left;

    while (!qu.empty())
    {
        p = qu.front().first;
        hd = qu.front().second;

        qu.pop();

        if (hd > rightMax)
        {
            rightMax = hd;
            Right.push_back(p->data);
        }
        else if (hd < leftMin)
        {
            leftMin = hd;
            Left.push(p->data);
        }

        if (p->left)
            qu.push({p->left, hd - 1});

        if (p->right)
            qu.push({p->right, hd + 1});
    }

    vector<int> ans;

    while (!Left.empty())
    {
        ans.push_back(Left.top());
        Left.pop();
    }

    ans.push_back(root->data);

    for (auto it : Right)
    {
        ans.push_back(it);
    }

    return ans;
}

int main()
{
}