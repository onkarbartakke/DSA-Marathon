#include<bits/stdc++.h>

using namespace std;


class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x=0)
    {
        data=x;
        left = NULL;
        right = NULL;
    }
};

void StoreInorder(Node *r, vector<Node*>&v)
{
    if(r==NULL)
    return;

    StoreInorder(r->left,v);
    v.push_back(r);
    StoreInorder(r->right,v);
}

Node* BuildBalancedBST(vector<Node*>&v, int left, int right)
{
    if(left>right)
    return NULL;


    int mid = (left + right)/2;
    Node *r = v[mid];
    r->left = BuildBalancedBST(v,left,mid-1);
    r->right = BuildBalancedBST(v,mid+1,right);

    return r;
}


int main()
{

}