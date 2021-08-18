#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int x = 0)
    {
        data = x;
        next = NULL;
    }
};

Node* getTail(Node *h)
{
    if(h==NULL || h->next==NULL)
    return h;


    while(h->next!=NULL)
    h=h->next;

    return h;
}

Node* partition(Node *head, Node *tail, Node **newHead, Node **newTail)
{
    Node *curr,*prev,*pivot;

    pivot=tail;
    curr=head;
    prev=NULL;

    

    while(curr!=pivot)
    {
        if(curr->data < pivot->data)
        {
            if((*newHead)==NULL)
            {
                *newHead=curr;
            }

            prev=curr;
            curr=curr->next;
        }
        else
        {
            Node *t=curr->next;

            if(prev)
            prev->next=curr->next;

            curr->next=NULL;

            //(*newTail)->next=curr;
            //(*newTail)=curr;
            tail->next=curr;
            tail=curr;

            curr=t;

        }
    }

    if((*newHead)==NULL)
    {
        (*newHead)=pivot;
    }

    (*newTail)=tail;

    return pivot;

}

Node* RecurrQuickSort(Node *head, Node *tail)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node *pivot;
    Node *newHead,*newTail;
    newHead=NULL;
    newTail=NULL;
    pivot=NULL;

    pivot=partition(head,tail,&newHead,&newTail);

    if(newHead!=pivot)
    {
        Node *t=newHead;

        while(t->next!=pivot)
        t=t->next;

        t->next=NULL;

        newHead=RecurrQuickSort(newHead,t);

        t=getTail(newHead);
        t->next=pivot;
    }

    Node *h=pivot->next;
    pivot->next=NULL;

    pivot->next=RecurrQuickSort(h,newTail);

    return newHead;
}


void QuickSort(Node **href)
{
    Node *h=*(href);

    if(h==NULL || h->next==NULL)
    return;


    *(href)=RecurrQuickSort(h,getTail(h));
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

    QuickSort(&head);

    Display(head);
}