#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
        int data;
        Node *lchild;
        Node *rchild;
        
        Node(int d=0)
        {
            this->data=d;
            this->rchild=NULL;
            this->lchild=NULL;
        }
};

Node* insert(Node* p, int d)
{
    if(p==NULL)
    {
        Node *t;
        t=new Node(d);
        return t;
    }
    else if(p->data < d)
    {
        p->rchild=insert(p->rchild,d);
    }
    else if(p->data > d)
    {
        p->lchild=insert(p->lchild,d);
    }

    return p;
}

int Height(Node *p)
{
    if(p==NULL)
    return 0;

    int x=Height(p->rchild);
    int y=Height(p->lchild);
    return max(x,y)+1;
}

Node* InPred(Node *p)
{
    while(p && p->rchild)
    {
        p=p->rchild;
    }

    return p;
}

Node* InSucc(Node *p)
{
    while(p && p->lchild)
    {
        p=p->lchild;
    }

    return p;
}

Node* Delete(Node *p, int key)
{
    if(p==NULL)
    return NULL;

    if(p->data==key && p->lchild==NULL && p->rchild==NULL)
    {
        delete p;
        return NULL;
    }

    if(p->data < key)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else if(p->data > key)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(p->data==key)
    {
        Node *q;
        if(Height(p->lchild) > Height(p->rchild))
        {
           
            q=InPred(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }

    return p;
}

void display_inorder(Node *p)
{
    if(p==NULL)
    {
        return;
    }

    display_inorder(p->lchild);
    cout<<p->data<<" ";
    display_inorder(p->rchild);
}

Node* Create_from_preorder(int pre[],int n)
{
    Node *p;
    Node *root;
    p=new Node(pre[0]);
    root=p;
    int i=1;
    stack<Node*>st;
    while(i<n)
    {
        if(p->data > pre[i])
        {
            Node *t=new Node(pre[i]);
            p->lchild=t;
            st.push(p);
            p=t;
        }
        else if(p->data < pre[i])
        {
            if(st.empty())
            {
                Node *t=new Node(pre[i]);
                p->rchild=t;
                p=t;
            }
            else if(pre[i] < (st.top())->data)
            {
                Node *t=new Node(pre[i]);
                p->rchild=t;
                p=t;
            }
            else if(pre[i] > (st.top())->data)
            {
                Node *q=st.top();
                st.pop();
                Node *t=new Node(pre[i]);
                q->rchild=t;
                p=t;
            }
        }

        i++;
    }

    return root;
}

int main()
{
    int n,i,key;
    Node *root=NULL;
    cout<<"Enter num of Elements to be inserted : ";
    cin>>n;

    cout<<"Enter the Elements : ";
    i=0;
    while(i<n)
    {
        int x;
        cin>>x;
        root=insert(root,x);
        i++;
    }

    cout<<"\n";
    display_inorder(root);


    cout<<"\nEnter the Element to be Deleted : ";
    cin>>key;
    root=Delete(root,key);
    display_inorder(root);

    Node *root1;
    cout<<"\nEnter the num of Elements in Preorder : ";
    int m;
    cin>>m;
    int pre[m];
    i=0;
    while(i<m)
    {
        cin>>pre[i];
        i++;
    }
    root1=Create_from_preorder(pre,m);
    display_inorder(root1);
}