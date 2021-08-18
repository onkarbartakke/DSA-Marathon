#include<iostream>
#include<cmath>
using namespace std;

class trie_node
{
    public:
        trie_node *lchild;
        trie_node *rchild;
        trie_node()
        {
            lchild=NULL;
            rchild=NULL;
        }
};


void insert(int n, trie_node *root)
{
    trie_node *curr=root;

    int i,b;
    for(i=31;i>=0;i--)
    {
        b=(n>>1)&1;

        if(b==1)
        {
            if(curr->rchild==NULL)
            {
                curr->rchild=new trie_node();
            }
            curr=curr->rchild;
        }
        else
        {
            if(curr->lchild==NULL)
            {
                curr->lchild=new trie_node();
            }
            curr=curr->lchild;
        }
    } 
}

int findmax_Xor(int a[], int n, trie_node *root)
{
    trie_node *curr=root;
    int i,b,j;
    int curr_xor, max_xor;
    max_xor=-1;
    for(i=0;i<n;i++)
    {
        curr_xor=0;
        curr=root;
        for(j=31;j>=0;j--)
        {
            b=(a[i]>>j)&1;

            if(b==1)
            {
                if(curr->lchild)
                {
                    curr_xor+=pow(2,j);
                    curr=curr->lchild;
                }
                else
                {
                    curr=curr->rchild;
                }
            }
            else
            {
                if(curr->rchild)
                {
                    curr_xor+=pow(2,j);
                    curr=curr->rchild;
                }
                else
                {
                    curr=curr->lchild;
                }
            }
        }

        max_xor=max(max_xor, curr_xor);
    }

    return max_xor;
}

int main()
{
    int i,j,n;
    trie_node *root=new trie_node();
    cout<<"\nEnter the num of Elements : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the Elements : \n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<n;i++)
    {
        insert(a[i],root);
    }

    int m=findmax_Xor(a,n,root);

    cout<<"\n Max XOR : "<<m;
}