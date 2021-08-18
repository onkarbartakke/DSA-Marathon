#include<bits/stdc++.h>

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

Node*  create_Tree(Node *r)
{
    int i,j,n,x;
    cout<<"\nEnter the Value of Root : ";
    cin>>x;
    r=new Node(x);
    queue<Node*>qu;
    qu.push(r);

    while(!qu.empty())
    {
        Node *t=qu.front();
        qu.pop();

        cout<<"\nEnter the left child of "<<t->data<<" : ";
        cin>>x;
        if(x>0)
        {
            t->left=new Node(x);
            qu.push(t->left);
        }

        cout<<"\nEnter the right child of "<<t->data<<" : ";
        cin>>x;
        if(x>0)
        {
            t->right=new Node(x);
            qu.push(t->right);
        }
    }

    return r;
}


bool Anagramic_levels(Node *r1, Node *r2)
{
    if(r1==NULL && r2==NULL)
    return true;
    if(r1==NULL || r2==NULL)
    return false;

    if(r1->data!=r2->data)
    return false;

    queue<Node*>q1,q2;

    q1.push(r1);
    q2.push(r2);

    int s1,s2;
    s1=q1.size();
    s2=q2.size();
    vector<int>v1,v2;
    Node *n1,*n2;
    while(!q1.empty())
    {
        n1=q1.front();
        q1.pop();

        n2=q2.front();
        q2.pop();

        if(n1->left)
        {
            v1.push_back(n1->left->data);
            q1.push(n1->left);
        }

        if(n1->right)
        {
            v1.push_back(n1->right->data);
            q1.push(n1->right);
        }

        if(n2->left)
        {
            v2.push_back(n2->left->data);
            q2.push(n2->left);
        }

        if(n2->right)
        {
            v2.push_back(n2->right->data);
            q2.push(n2->right);
        }

        s1--;
        s2--;

        if(s1==0 && s2==0)
        {
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());

            if(v1!=v2)
            return false;

            s1=q1.size();
            s2=q2.size();

            if(s1!=s2)
            return false;
        }

    }

    if(q1.empty() && q1.empty())
    return true;
    else
    return false;

}
int main()
{
    Node *r1,*r2;
    cout<<"Enter the Details of 1st Tree : \n";
    r1=create_Tree(r1);
    cout<<"\nEnter the Details of 2nd Tree : \n";
    r2=create_Tree(r2);

    if(Anagramic_levels(r1,r2))
    {
        cout<<"\nAll Levels  of Trees are Anagramic\n";
    }
    else
    {
        cout<<"\nLevels are not Anagramic\n";
    }
}