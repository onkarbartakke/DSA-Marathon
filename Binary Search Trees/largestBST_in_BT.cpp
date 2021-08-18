#include<iostream>
#include<climits>
#include<stack>
#include<queue>

using namespace std;

class Node
{
    public:
    int data;
    Node* lchild;
    Node* rchild;
    Node(int d=0)
    {
        data=d;
        lchild=NULL;
        rchild=NULL;
    }
};

struct info
{
    int min;
    int max;
    int size;
    bool isBST;
    int ans;
};


Node* createBT(Node* root)
{
    int x;
    cout<<"Enter the root : ";
    cin>>x;
    root=new Node(x);
    queue<Node*>qu;

    qu.push(root);

    while(!qu.empty())
    {
        Node *t;
        t=qu.front();
        qu.pop();

        cout<<"\nEnter left child of "<<t->data<<" : ";
        cin>>x;
        if(x>=0)
        {
            t->lchild=new Node(x);
            qu.push(t->lchild);
        }

        cout<<"\nEnter right child of "<<t->data<<" : ";
        cin>>x;
        if(x>=0)
        {
            t->rchild=new Node(x);
            qu.push(t->rchild);
        } 
    }

    return root;
}

info LargestBT(Node* root)
{
    info curr;
    if(root==NULL)
    {
        curr.min=INT_MAX;
        curr.max=INT_MIN;
        curr.size=0;
        curr.ans=0;
        curr.isBST=true;

        return curr;
    }

    if(root->lchild==NULL && root->rchild==NULL)
    {
        curr.min=root->data;
        curr.max=root->data;
        curr.size=1;
        curr.ans=1;
        curr.isBST=true;

        return curr; 
    }

    info leftBT=LargestBT(root->lchild);
    info rightBT=LargestBT(root->rchild);

    curr.size=(1+leftBT.size+rightBT.size);

    if(leftBT.isBST && rightBT.isBST && leftBT.max<root->data && root->data<rightBT.min)
    {
        curr.isBST=true;
        curr.min=min(leftBT.min, min(rightBT.min,root->data));
        curr.max=max(rightBT.max, max(leftBT.max,root->data));

        curr.ans=curr.size;
        return curr;
    }

    curr.isBST=false;
    curr.ans=max(leftBT.ans,rightBT.ans);
    return curr;
}

int main()
{
    Node *root=NULL;
    root=createBT(root);

    info t;
    t=LargestBT(root);
    cout<<"\nLargest BST inside given BT is "<<t.ans;
}