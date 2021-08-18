#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    
};


Node* inPlace(Node *root)
{
 
    if(root==NULL || root->next==NULL)
    return root;
    
    Node *temp=root;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    
    Node *left=temp->next;
    temp->next=NULL;
    
    
    Node *to_attach=inPlace(root->next);
    root->next=left;
    left->next=to_attach;
    
    return root;
}

void display(Node *t)
{
    cout<<"\n\n";
    while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
int main()
{
    int n,i;
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"\nEnter the elements : ";
    Node *head,*tail;
    head=NULL;
    tail=NULL;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        Node *t=new Node;
        t->data=x;
        t->next=NULL;

        if(head==NULL)
        {
            head=t;
            tail=t;
        }
        else
        {
            tail->next=t;
            tail=t;
        }
    }

    Node *h=inPlace(head);
    display(h);
}