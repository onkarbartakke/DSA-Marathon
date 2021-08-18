#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int d=0)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};


Node* ReverseDLL(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node *pre,*curr;

    pre=NULL;
    curr=head;

    while(curr)
    {
        curr->prev=curr->next;
        curr->next=pre;

        pre=curr;
        curr=curr->prev;
    }

    return pre;
}

void Display(Node *head)
{
    cout<<"\n\n";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    int n,i,x;
    Node *head=NULL,*tail=NULL;

    cout<<"Enter the number of Elements : ";
    cin>>n;

    cout<<"\nEnter the Elements : \n";
    for(i=0;i<n;i++)
    {
        cin>>x;

        if(head==NULL)
        {
            head=new Node(x);
            tail=head;
        }
        else
        {
            Node *t=new Node(x);
            tail->next=t;
            t->prev=tail;
            tail=t;
        }
    }

    head=ReverseDLL(head);

    Display(head);
}