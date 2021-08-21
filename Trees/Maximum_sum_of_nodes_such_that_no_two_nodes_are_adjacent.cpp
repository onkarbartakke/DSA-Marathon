#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include<unordered_set>
#include<unordered_map>

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


int maxgrandChildsum(Node *root, unordered_map<Node*, int>&mp)
{
    if(root==NULL)
    return 0;

    int sum = 0;
    if(root->left)
    sum+=getMaxSumUntil(root->left->left,mp)+getMaxSumUntil(root->left->right);

    if(root->right)
    sum+=getMaxSumUntil(root->right->left,mp)+getMaxSumUntil(root->right->right);

    return sum;

}

int getMaxSumUntil(Node *root, unordered_map<Node*, int>&mp)
{
    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    {
        mp[root]=root->data;
        return mp[root];
    }

    if(mp.find(root)!=mp.end())
    return mp[root];

    int include=root->data+maxgrandChildsum(root,mp);

    int exclude=getMaxSumUntil(root->left)+getMaxSumUntil(root->right);

    mp[root]=max(include,exclude);

    return mp[root];
}

int getMaxSum(Node *root)
{
    if(root==NULL)
    return 0;

    unordered_map<Node*,int>mp;

    int include=(root->data)+maxgrandChildsum(root,mp);

    int exclude=getMaxSumUntil(root->left,mp)+getMaxSumUntil(root->right,mp)

    return max(include,exclude);
}


int main()
{

}