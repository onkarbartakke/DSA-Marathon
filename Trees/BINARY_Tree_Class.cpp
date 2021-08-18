#include<iostream>
#include<stack>
#include<queue>
typedef int item;
using namespace std;

struct Node
{
    item data;
    Node *lchild;
    Node *rchild;
};

class Tree
{
    private:
        Node *root;
    public:
        Tree();
        Node* get_root(){ return root; }
        void preorder(Node *p);
        void inorder(Node *p);
        void postorder(Node *p);
        void Ipreorder();
        void Iinorder();
        void Ipostorder();
        void Levelorder();
        int count_Nodes(Node *p);
        int height(Node *p);
        int degree_2_Nodes(Node *p);
        int Leaf_Nodes(Node *p);
        int Non_Leaf_Nodes(Node *p);
        int degree_1_Nodes(Node *p);
};

Tree::Tree()
{
    Node *p,*t;
    queue<Node*>npq;  //Node-Ptr-Queue
    int x;
    cout<<"\nEnter the value of Root : ";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    npq.push(root);

    while(!npq.empty())
    {
        p=npq.front();
        npq.pop();
        cout<<"\nEnter the Left Child of "<<p->data<<" : ";
        cin>>x;
        if(x!=0)
        {
            t=new Node;
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->lchild=t;
            npq.push(t);
        }


        cout<<"\nEnter the Right child of "<<p->data<<" : ";
        cin>>x;
        if(x!=0)
        {
            t=new Node;
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->rchild=t;
            npq.push(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void Tree::postorder(Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::Ipreorder()
{
    stack<Node*>npst;
    Node *p=root;
    while(p!=NULL || !npst.empty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            npst.push(p);
            p=p->lchild;
        }
        else
        {
            p=npst.top();
            npst.pop();
            p=p->rchild;
        }
    }
}

void Tree::Iinorder()
{
    Node *p=root;
    stack<Node*>npst;
    while(p!=NULL || !npst.empty())
    {
        if(p)
        {
            npst.push(p);
            p=p->lchild;  
        }
        else
        {
            p=npst.top();
            npst.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

void  Tree::Ipostorder()
{
    Node *p=root;
    stack<long int>st;
    long int temp;
    while(p!=NULL || !st.empty())
    {
        if(p)
        {
            st.push((long int)p);
            p=p->lchild;
        }
        else
        {
            temp=st.top();
            st.pop();

            if(temp>0)
            {
                st.push(-1*temp);
                p=((Node*)temp)->rchild;
            }
            else
            {
                cout<<((Node*)(-1*temp))->data<<" ";
                p=NULL;
            }
        }
    }

}

void Tree::Levelorder()
{
    Node *p=root;
    queue<Node*>npq;
    cout<<p->data<<" ";

    npq.push(p);
    while(!npq.empty())
    {
        p=npq.front();
        npq.pop();

        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            npq.push(p->lchild);
        }

        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            npq.push(p->rchild);
        }

    }
}

int Tree::count_Nodes(Node *p)
{
    int x,y;
    if(p)
    {
        x=count_Nodes(p->lchild);
        y=count_Nodes(p->rchild);

        return x+y+1;
    }

    return 0;
}

int Tree::height(Node *p)
{
    int x=0,y=0;
    if(p==NULL)
    return 0;
    else
    {
        x=height(p->lchild);
        y=height(p->rchild);

        if(x>y)
        return x+1;
        else
        return y+1;
    }
}

int Tree::degree_2_Nodes(Node *p)
{
    int x,y;
    x=0;
    y=0;

    if(p)
    {
        x=degree_2_Nodes(p->lchild);
        y=degree_2_Nodes(p->rchild);

        if(p->lchild && p->rchild)
        return x+y+1;
        else
        return x+y;
    }

    return 0;
}

int Tree::Leaf_Nodes(Node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=Leaf_Nodes(p->lchild);
        y=Leaf_Nodes(p->rchild);

        if(!p->lchild && !p->rchild)
        return x+y+1;
        else
        return x+y;
    }
    return 0;
}

int Tree::Non_Leaf_Nodes(Node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=Non_Leaf_Nodes(p->lchild);
        y=Non_Leaf_Nodes(p->rchild);

        if(p->lchild || p->rchild)
        return x+y+1;
        else
        return x+y;
    }
    return 0;
}

int Tree::degree_1_Nodes(Node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=degree_1_Nodes(p->lchild);
        y=degree_1_Nodes(p->rchild);

        if(p->lchild!=NULL ^ p->rchild!=NULL)
        return x+y+1;
        else
        return x+y;
    }
    return 0;
}


int main()
{
    Tree T;

    Node *p=T.get_root();
    cout<<"\n\n";
    cout<<"Preorde Traversal is : \n";
    T.preorder(p);

    cout<<"\n\n";
    cout<<"Iterative Preorde Traversal is : \n";
    T.Ipreorder();

    cout<<"\n\n";
    cout<<"Inorder Traversal is : \n";
    T.inorder(p);

    cout<<"\n\n";
    cout<<"Iterative Inorder Traversal is : \n";
    T.Iinorder();

    cout<<"\n\n";
    cout<<"Postorder Travesal is : \n";
    T.postorder(p);

    cout<<"\n\n";
    cout<<"Iterative Postorder is : \n";
    T.Ipostorder();

    cout<<"\n\n";
    cout<<"Level Order Traversal is : \n";
    T.Levelorder();

    cout<<"\n\n";
    int n=T.count_Nodes(p);
    cout<<"Number of Nodes are : "<<n;

    cout<<"\n\n";
    n=T.degree_2_Nodes(p);
    cout<<"Number of Degree 2 nodes are : "<<n;

    cout<<"\n\n";
    n=T.Leaf_Nodes(p);
    cout<<"Number of Leaf Nodes (degree 0) are : "<<n;

    cout<<"\n\n";
    n=T.Non_Leaf_Nodes(p);
    cout<<"Number of Non leaf noes (degree 1 or 2) are : "<<n;

    cout<<"\n\n";
    n=T.degree_1_Nodes(p);
    cout<<"Number of Degree 1 nodes are : "<<n;

    cout<<"\n\n";
    int h=T.height(p);
    cout<<"Height of Bineary Tree is : "<<h-1;
}

