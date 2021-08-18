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


void Display(Node *head)
{
    cout<<"\n\n";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void Find_Pairs(Node *head, Node *tail, int sum)
{
    Node *left,*right;
    left=head;
    right=tail;
    int s;
    while(left!=right)
    {
        s=(left->data)+(right->data);

        if(s==sum)
        {
            cout<<"( "<<left->data<<" , "<<right->data<<" )\n";
            left=left->next;
            right=right->prev;
        }
        else if(s<sum)
        {
            left=left->next;
        }
        else if(s>sum)
        {
            right=right->prev;
        }
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
    
    cout<<"Enter the Sum : ";
    int sum;
    cin>>sum;

    Find_Pairs(head,tail,sum);
}