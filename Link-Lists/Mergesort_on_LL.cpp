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

void FrontBackSplit(Node *src, Node **front, Node **back)
{
    Node *fast,*slow;
    fast=src;
    slow=src;

    while(fast!=NULL)
    {
        fast=fast->next;

        if(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }

    *(front)=src;
    *(back)=slow->next;

    slow->next=NULL;
}

Node* SortedMerge(Node *a, Node *b)
{
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;

    Node *result;

    if(a->data < b->data)
    {
        result=a;
        result->next=SortedMerge(a->next,b);
    }
    else
    {
        result=b;
        result->next=SortedMerge(a,b->next);
    }

    return result;
}

void MergeSort(Node **href)
{
    Node *h=*(href);

    if(h==NULL || h->next==NULL)
    return;

    Node *a,*b;
    FrontBackSplit(h,&a,&b);
    MergeSort(&a);
    MergeSort(&b);

    *(href)=SortedMerge(a,b);
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

    MergeSort(&head);

    Display(head);
}