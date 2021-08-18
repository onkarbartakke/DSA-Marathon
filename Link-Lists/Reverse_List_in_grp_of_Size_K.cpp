#include<iostream>
#include<vector>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int x=0)
    {
        data=x;
        next=NULL;
    }
};


void Display(Node *head)
{
    Node *t=head;
    cout<<"\n\n";
    while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }    
}

Node* Reverse_in_K(Node *head, int n, int k)
{
    if(head==NULL)
    return head;

    Node *curr,*prev,*next;
    curr=head;
    prev=NULL;
    next=NULL;

    int count=0;

    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;

        curr=next;
        count++;
    }

    if(next!=NULL)
    head->next=Reverse_in_K(next,n,k);

    return prev;
}

int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    int n,i,x,k;
    cout<<"Enter the Num of Elemenets : ";
    cin>>n;

    cout<<"\nEnter the N elements : \n";

    for(i=0;i<n;i++)
    {
        cin>>x;
        Node *p=new Node(x);

        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            tail->next=p;
            tail=p;
        }
    }  

    cout<<"\nEnter the value of k : ";
    cin>>k;

    head=Reverse_in_K(head,n,k);

    Display(head);
   
}