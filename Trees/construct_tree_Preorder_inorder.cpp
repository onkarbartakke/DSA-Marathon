#include<iostream>
#include<queue>
#include<stack>

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

int search(int inorder[],int start, int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        return i;
    }
    return -1;
}

Node* BuildTree(int preorder[], int inorder[], int start, int end)
{
    if(start>end)
    return NULL;


    static int index=0;
    int curr=preorder[index];
    index++;
    Node *node=new Node(curr);

    int pos=search(inorder,start,end,curr);

    if(start==end)
    return node;

    node->lchild=BuildTree(preorder,inorder,start,pos-1);
    node->rchild=BuildTree(preorder,inorder,pos+1,end);

    return node;
}

void Display_inorder(Node *p)
{
    if(p!=NULL)
    {
        Display_inorder(p->lchild);
        cout<<p->data<<" ";
        Display_inorder(p->rchild);
    }

}

void Display_preorder(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        Display_preorder(p->lchild);
        Display_preorder(p->rchild);
    }
}

void Display_levelorder(Node *p)
{
    queue<Node*>qu;
    qu.push(p);
    qu.push(NULL);

    while(!qu.empty())
    {
        if(qu.front()==NULL)
        {
            qu.pop();
            qu.push(NULL);
            cout<<"\n";

            if(qu.front()==NULL && qu.back()==NULL)
            break;
        }
        else
        {
            Node *t=qu.front();
            cout<<t->data<<" ";
            qu.pop();

            if(t->lchild)
            qu.push(t->lchild);

            if(t->rchild)
            qu.push(t->rchild);
        }
    }
}

void Display_postorder(Node *r)
{
    if(r == NULL)
    return;

    Display_postorder(r->lchild);
    Display_postorder(r->rchild);
    cout<<r->data<<" ";
    return;
}
int main()
{
    int n,i;
    cout<<"Enter the num of elements in tree : ";
    cin>>n;
    int preorder[n],inorder[n];
    cout<<"Enter the Preorder sequence : \n";
    for(i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    cout<<"Enter the Inorder sequence : \n";
    for(i=0;i<n;i++)
    {
        cin>>inorder[i];
    }

    Node *root=NULL;
    root=BuildTree(preorder,inorder,0,n-1);

    cout<<"Inorder : \n";
    Display_inorder(root);
    cout<<"\n";

    cout<<"Preorder : \n";
    Display_preorder(root);
    cout<<"\n";
    
    cout<<"Level order : \n";
    Display_levelorder(root);

    cout<<"Post Order : \n";
    Display_postorder(root);
    
}