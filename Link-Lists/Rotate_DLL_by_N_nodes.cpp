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


Node* Rotate(Node *head , Node* tail , int n)
{
    if(n==0)
    return head;

    int i=0;
    Node *h=head;
    while(i<n)
    {
        h=h->next;
        i++;
    }

    Node *t=h->prev;

    t->next=NULL;
    h->prev=NULL;

    tail->next=head;
    head->prev=tail;

    return h;
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

    cout<<"Enter the value of N : ";
    cin>>n;

    head=Rotate(head,tail,n);

    Display(head);
}