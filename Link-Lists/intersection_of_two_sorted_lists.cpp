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

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *head,*tail;
    head=NULL;
    tail=NULL;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data==head2->data)
        {
            if(head==NULL)
            {
                head=new Node(head1->data);
                tail=head;
            }
            else
            {
                tail->next=new Node(head1->data);
                tail=tail->next;
            }
            
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data <  head2->data)
        {
            head1=head1->next;
        }
        else
        {
            head2=head2->next;
        }
        
    }
    
    return head;
}



int main()
{

}