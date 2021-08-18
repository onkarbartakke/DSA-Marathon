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

Node* IterativeReverse(Node *head, int n)
{
    Node *p1,*p2,*p3;
    p1=p2=p3=NULL;

    p1=head;

    while(p1)
    {
        p3=p2;
        p2=p1;
        p1=p1->next;

        p2->next=p3;
    }

    Node *h=p2;

    return h;
}


Node* RecursiveReverse(Node *head, int n)
{
    if(head->next==NULL)
    {
        return head;
    }

    Node *t=head;
    Node *tNext=t->next;
    Node *h=RecursiveReverse(t->next,n);
    
    tNext->next=t;
    t->next=NULL;

    return h;
}

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


int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    int n,i,x;
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

    Display(head);

    head=IterativeReverse(head,n);

    Display(head);

    head=RecursiveReverse(head,n);

    Display(head);
}