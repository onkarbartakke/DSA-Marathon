#include<iostream>
#include<vector>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d=0)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node* r, int  val, int &succ)
{
    if(r==NULL)
    {
        Node *t=new Node(val);

        return t;
    }

    if(r->data > val)
    {
        succ=r->data;
        r->left=insert(r->left,val,succ);
    }
    else
    {
        r->right=insert(r->right,val,succ);
    }

    return r;
}
void Replace(vector<int>&a, int n, vector<int>&ans)
{
    ans[n-1]=-1;

    Node *root=new Node(a[n-1]);
    int i,j;
    for(i=n-2;i>=0;i--)
    {
        j=-1;
        root=insert(root,a[i],j);

        ans[i]=j;
    }
}

int main()
{
    int n,i;
    cout<<"Enter the Num of Elements : ";
    cin>>n;
    cout<<"\nEnter the N elements : \n";
    vector<int>a(n);

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<int>ans(n);

    Replace(a,n,ans);

    cout<<"\n";
    for(i=0;i<n;i++)
    cout<<ans[i]<<" ";
}