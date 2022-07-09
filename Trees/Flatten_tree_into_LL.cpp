#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node *right;

    Node(int d=0)
    {
        data=0;
        left=NULL;
        right=NULL;
    }
};

void flatten(Node *root)
{
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL)
   return ;

   if(root->left)
   {
       flatten(root->left);

       Node *temp=root->right;

       root->right=root->left;
       root->left=NULL;

       Node *t=root;

       while(t->right!=NULL)
        t=t->right;
        
        t->right=temp;
   }

   flatten(root->right);
}

int main()
{
    
}