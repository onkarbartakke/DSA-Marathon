#include<iostream>

using namespace std;
// BT19CSE012 Onkar Bartakke
class Node
{
    public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x = 0)
    {
        data = x;
        next = NULL;
    }
};


Node* merge(Node *h1, Node *h2)
{
    if(h1==NULL)
    return h2;
    if(h2==NULL)
    return h1;
    
    Node *result;
    
    if(h1->data < h2->data)
    {
        result=h1;
        result->bottom=merge(h1->bottom, h2);
    }
    else
    {
        result=h2;
        result->bottom=merge(h1,h2->bottom);
    }
    
    return result;
}


Node* flatten(Node *root)
{
   // Your code here
    if(root==NULL || root->next==NULL)
    return root;
    
    Node *h1,*h2;
    h1=root;
    h2=flatten(root->next);
    
    h1->next=NULL;
    
    return merge(h1,h2);
  
}

int main()
{

}