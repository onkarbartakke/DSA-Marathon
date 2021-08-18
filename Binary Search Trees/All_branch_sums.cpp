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

    Node(int d = 0)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};



int getCount(Node *root, int l, int h)
{
  // your code goes here 
  if(root==NULL)
  return 0;
  
  if(root->data==l && root->data==h)
  return 1;
  
  if(root->data>=l && root->data<=h)
  {
      return 1 + getCount(root->left,l,h) + getCount(root->right,l,h);
  }
  
  if(root->data < l)
  return getCount(root->right,l,h);
  else
  return getCount(root->left,l,h);
}

int main()
{
    
}