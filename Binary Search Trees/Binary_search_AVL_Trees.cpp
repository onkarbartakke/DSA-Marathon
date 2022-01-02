
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node
{
    public:
        int data;
        Node *lchild;
        Node *rchild;
        int height;
        Node(int d=0)
        {
            this->data=d; 
            this->rchild=NULL;
            this->lchild=NULL;
            this->height=1;
        }
};


int NodeHeight(Node *p)
{
    int x,y;
    x=(p && p->lchild)?(p->lchild->height):0;
    y=(p && p->rchild)?(p->rchild->height):0;

    return max(x,y)+1;
}

int BalanceFactor(Node *p)
{
    int x,y;
    x=(p && p->lchild)?(p->lchild->height):0;
    y=(p && p->rchild)?(p->rchild->height):0; 

    return x-y;  
}


Node* LL_Rotation(Node* p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    return pl;
}

Node* RR_Rotation(Node* p)
{
    Node *pr=p->rchild;
    Node *prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    return pr;
}

Node* LR_Rotation(Node* p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    return plr;
}

Node* RL_Rotation(Node *p)
{
    Node *pr=p->rchild;
    Node *prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;

    prl->lchild=p;
    prl->rchild=pr;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    return prl;
}


Node* insertAVL(Node* p, int d)
{
    if(p==NULL)
    {
        Node *t;
        t=new Node(d);
        t->height=1;
        return t;
    }
    else if(p->data < d)
    {
        p->rchild=insertAVL(p->rchild,d);
    }
    else if(p->data > d)
    {
        p->lchild=insertAVL(p->lchild,d);
    }

    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    return LL_Rotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
    return LR_Rotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
    return RR_Rotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==1)
    return RL_Rotation(p);

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

Node* DeleteAVL(Node *p, int key)
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
        p->rchild=DeleteAVL(p->rchild,key);
    }
    else if(p->data > key)
    {
        p->lchild=DeleteAVL(p->lchild,key);
    }
    else if(p->data==key)
    {
        Node *q;
        if(Height(p->lchild) > Height(p->rchild))
        {
           
            q=InPred(p->lchild);
            p->data=q->data;
            p->lchild=DeleteAVL(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=DeleteAVL(p->rchild,q->data);
        }
    }

    p->height=NodeHeight(p);


    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    return LL_Rotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
    return LR_Rotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
    return RR_Rotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==1)
    return RL_Rotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
    return LL_Rotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0)
    return RR_Rotation(p);

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

void display_levelorder(Node *p)
{
    queue<Node*>qu;
    qu.push(p);
    qu.push(NULL);
    Node *t;
    while(!qu.empty())
    {
        if(qu.front()==NULL)
        {
            cout<<"\n";
            qu.pop();
            qu.push(NULL);

            if(qu.front()==NULL && qu.back()==NULL)
            break;
        }
        else
        {
            t=qu.front();
            qu.pop();
            cout<<t->data<<" ";

            if(t->lchild!=NULL)
            {
                qu.push(t->lchild);
            }

            if(t->rchild!=NULL)
            {
                qu.push(t->rchild);
            }
        }
    }
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
        root=insertAVL(root,x);
        i++;
    }

    cout<<"\n";
    display_inorder(root);
    cout<<"\n****************\n";

    
    /*
    cout<<root->data<<" ";
    cout<<root->lchild->data<<" ";
    cout<<root->rchild->data<<" ";
    */
   display_levelorder(root);
    
    cout<<"\nEnter the Element to be Deleted : ";
    cin>>key;
    root=DeleteAVL(root,key);
    display_inorder(root);
    cout<<"\n****************\n";
    display_levelorder(root);
    /*
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
    root1=Create_from_postorder(pre,m);
    display_inorder(root1);
    */
}