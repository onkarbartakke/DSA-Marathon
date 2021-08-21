#include<iostream>
#include<vector>
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

bool getpath(Node *r, int n, vector<int>&path)
{
    if(r==NULL)
    return false;

    path.push_back(r->data);

    if(r->data==n)
    {
        return true;
    }

    if(getpath(r->lchild,n,path) || getpath(r->rchild,n,path))
    return true;
    else
    {
        path.pop_back();
        return false;
    }
    
}

int Lowest_common_ancestor(Node *root, int n1 , int n2)
{
    vector<int>path1;
    vector<int>path2;

    if(getpath(root,n1,path1) && getpath(root,n2,path2))
    {
        int i=0;
        while(i<path1.size() && i<path2.size())
        {
            if(path1[i]!=path2[i])
            {
                return path1[i-1];
            }
            i++;
        }
    }

    return -1;
}

Node* Lowest_common_ancestor2(Node *root, int n1, int n2)
{
    if(root==NULL)
    return NULL;

    if(root->data==n1 || root->data==n2)
    return root;

    Node *left;
    Node *right;
    left=Lowest_common_ancestor2(root->lchild,n1,n2);
    right=Lowest_common_ancestor2(root->rchild,n1,n2);

    if(left && right)
    return root;

    if(left==NULL)
    return right;
    else
    return left;

}

int main()
{
    int n,i;
    Node *root;
    root=create_tree(root);

    cout<<"\nEnter the Node 1 : ";
    int n1,n2;
    cin>>n1;
    cout<<"Enter the Node 2 : ";
    cin>>n2;

    i=Lowest_common_ancestor(root,n1,n2);
    if(i==-1)
    {
        cout<<"\nLowest common doesnt exists for n1 andd n2\n";
    }
    else
    {
        cout<<"Lowest common is "<<i;
    }

}