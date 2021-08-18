#include<iostream>

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


Node* FindLCA(Node *r, int m1, int m2)
{
    if(r==NULL)
    return NULL;
    
    if(r->left!=NULL && r->right!=NULL)
    {
        if(r->left->data==m1 && r->right->data==m2)
        return r;
    }
    
     if(r->data >= m1 && r->data<= m2)
        return r;
    
    if(r->left)
    {
        if(m2 < r->data)
        return FindLCA(r->left,m1,m2);
    }
    
    if(r->right)
    {
        if(m1> r->data)
        return FindLCA(r->right,m1,m2);
    }
    
   
}

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   int m1=min(n1,n2);
   int m2=max(n1,n2);
   
   if(root==NULL)
   return NULL;
   
   Node *r=FindLCA(root,m1,m2);
   
   return r;
}
