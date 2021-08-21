#include<iostream>
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
            this->data=d;
            this->lchild=NULL;
            this->rchild=NULL;
        }
};

Node* create_tree(Node *root)
{

    cout<<"Enter the root : ";
    int x;
    cin>>x;
    root=new Node(x);
    queue<Node*>qu;
    qu.push(root);

    Node *t;
    while(!qu.empty())
    {
        t=qu.front();
        qu.pop();

        cout<<"Enter Left Child of "<<t->data<<" : ";
        cin>>x;

        if(x!=-1)
        {
            t->lchild=new Node(x);
            qu.push(t->lchild);
        }

        cout<<"Enter right child of "<<t->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            t->rchild=new Node(x);
            qu.push(t->rchild);
        }   
    }

    return root;
}

Node* Lowest_common_Ancestor(Node *root, int n1, int n2)
{
    if(root==NULL)
    return NULL;

    if(root->data==n1 || root->data==n2)
    return root;

    Node *left=Lowest_common_Ancestor(root->lchild,n1,n2);
    Node *right=Lowest_common_Ancestor(root->rchild,n1,n2);

    if(left && right)
    return root;

    if(left==NULL && right==NULL)
    return NULL;

    if(left==NULL)
    return right;
    else
    return left;
}

int Find_Dist(Node *root, int key)
{
    if(root==NULL)
    return -1;

    if(root->data==key)
    return 0;

    int left=Find_Dist(root->lchild,key);
    if(left!=-1)
    {
        return left+1;
    }

    int right=Find_Dist(root->rchild,key);
    if(right!=-1)
    {
        return right+1;
    }

    return -1;

}

int Dist_between_Nodes(Node *root, int n1, int n2)
{
    Node *lca=Lowest_common_Ancestor(root,n1,n2);

    int d1=Find_Dist(lca,n1);
    int d2=Find_Dist(lca,n2);

    return d1+d2;
}

int main()
{
    Node *root;
    root=create_tree(root);

    int n1,n2;
    cout<<"Enter the 1st Node : ";
    cin>>n1;
    cout<<"Enter the 2nd Node : ";
    cin>>n2;

    int ans=Dist_between_Nodes(root,n1,n2);
    cout<<"\nMin Dist between Nodes is : "<<ans;
}