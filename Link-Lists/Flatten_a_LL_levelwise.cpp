#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x = 0)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node* faltten(Node *head)
{
    if(head==NULL)
    return;

    Node *curr,*tail,*t;
    curr=head;
    tail=head;

    while(tail->next!=NULL)
    tail=tail->next;

    while(curr!=tail)
    {
        if(curr->bottom!=NULL)
        {
            tail->next=curr->bottom;

            t=curr->bottom;

            while(t->next!=NULL)
            t=t->next;

            tail=t;
        }

        curr=curr->next;
    }

    return head;
}

int main()
{

}