#include<iostream>

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


void Delete_loop(Node *head, Node *loop_node)
{
    Node *ptr1,*ptr2;
    ptr1=loop_node;
    ptr2=loop_node;

    int count=1;

    while(ptr2->next!=ptr1)
    {
        ptr2=ptr2->next;
        count++;
    }

    ptr1=head;
    ptr2=head;

    int i=0;
    while(i<count)
    {
        ptr2=ptr2->next;
        i++;
    }
   
    while(ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    while(ptr2->next!=ptr1)
    ptr2=ptr2->next;

    ptr2->next=NULL;
}

void Detect_Loop(Node *head)
{
    Node *fast,*slow;
    fast=head;
    slow=head;

    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow)
        {
            cout<<"\nLoop Exists\n";
            Delete_loop(head,slow);
            return;
        }
    }

    cout<<"\nLoop Dosent Exists\n";
    return;

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

    head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=head->next->next;

    Detect_Loop(head);

    Display(head);   
}



