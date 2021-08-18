#include<iostream>
#include<set>
#include<unordered_set>

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



void removeDuplicates(Node *head)
{
    unordered_set<int>st;

    Node *t=head;
    Node *prev=NULL;
    while(t)
    {
        if(st.find(t->data)!=st.end())
        {
            prev->next=t->next;
            t->next=NULL;
            delete t;

            t=prev->next;
        }
        else
        {
            st.insert(t->data);
            prev=t;
            t=t->next;
        }
    }
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

    removeDuplicates(head);

    Display(head);
}