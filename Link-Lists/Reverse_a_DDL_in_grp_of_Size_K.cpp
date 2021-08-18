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

Node* Reverse_in_K(Node *head, int k)
{
    Node *curr,*pre,*nex;
    int count=0;

    pre=NULL;
    curr=head;
    Node *newHead=NULL;

    while(count<k && curr!=NULL)
    {
        curr->prev=curr->next;
        curr->next=pre;


        pre=curr;
        curr=curr->prev;

        count++;
    }

    newHead=pre;
    newHead->prev=NULL;
    if(curr!=NULL)
    {
        head->next=Reverse_in_K(curr,k);
        head->next->prev=head;
    }

    return newHead;
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

    cout<<"Enter the value of K : ";
    int k;
    cin>>k;

    
    head=Reverse_in_K(head,k);
    Display(head);
}