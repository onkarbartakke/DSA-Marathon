#include <iostream>

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

Node *shiftLinkedList(Node *head, int k)
{
    // Write your code here.
    if (k == 0)
        return head;

    if (head == NULL || head->next == NULL)
        return head;

    Node *tail, *newHead, *newTail;

    tail = head;
    newHead = head;
    newTail = NULL;
    int count = 1;

    while (tail->next != NULL)
    {
        tail = tail->next;
        count++;
    }

    k = (k % count);
    if(k==0)
    return head;
    int jump = 0;
    if (k > 0)
    {
        jump = count - k;
    }
    else if (k < 0)
    {
        jump = (-k);
    }

    int i = 0;
    while (i < jump)
    {
        newTail = newHead;
        newHead = newHead->next;
        i++;
    }

    if (newTail)
        newTail->next = NULL;

    if (tail)
        tail->next = head;

    return newHead;
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

   cout<<"\nEnter the value of K : ";
   int k;
   cin>>k;

   head=shiftLinkedList(head,k);

    Display(head);
}


