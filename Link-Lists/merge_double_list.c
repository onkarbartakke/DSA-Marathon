#include<stdio.h>
#include<stdlib.h>
typedef int item;

typedef struct Node_tag
{
    item data;
    struct Node_tag* next;
    struct Node_tag* prev;

}Node;

Node* create_Node(item x)
{
    Node *ptr;
    ptr=(Node*)malloc(sizeof(Node));
    ptr->data=x;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}

Node* insert_at_start(Node *head, Node* nptr)
{
   if(head==NULL)
   {
       return nptr;
   }
   else
   {
       nptr->next=head;
       head->prev=nptr;
       return nptr;
   }   
}


Node* insert_at_end(Node *head, Node *nptr)
{
    if(head==NULL)
    {
        head=nptr;
        head->next=NULL;
        head->prev=NULL;
    }
    else
    {
        Node *ptr=head;

        while(ptr->next)
        {
            ptr=ptr->next;
        }

        ptr->next=nptr;
        nptr->prev=ptr;
        nptr->next=NULL;
    }

    return head;
}

Node* Delete_at_start(Node *head, item *x)
{
    if(head!=NULL)
    {
        Node *ptr;
        ptr=head;
        head=head->next;
        (*x)=ptr->data;
        ptr->next=NULL;
        head->prev=NULL;

        free(ptr);
    }

    return head;
}

Node* Delete_at_end(Node *head,item *x)
{
    if(head)
    {
        Node *ptr=head;
        while(ptr->next)
        {
            ptr=ptr->next;
        }

        *(x)=ptr->data;
        Node *qptr=ptr->prev;
        free(ptr);
        if(qptr)
        {
            qptr->next=NULL;
        }
        else
        {
            head=NULL;
        }
    }

    return head;
} 

void display(Node *head)
{
    printf("\n\n");
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

Node* reverse(Node *head)
{
    if(head->next==NULL)
    return head;
    Node *curr,*temp;
    curr=head;
    
    while(curr)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        
        curr=curr->prev;
    }
    
    return temp->prev;
}

Node* merge(Node *h1, Node *h2)
{
    Node *t1,*t2;
    t1=h1;
    t2=h2;
    Node *p1,*p2;
    Node *last=NULL;
    while(t1!=NULL && t2!=NULL)
    {
       p1=t1->next;
       p2=t2->next;

        if(last==NULL)
        {
            last=t1;
            t1=p1;
        }
        else
        {
            last->next=t2;
            t2->prev=last;
            last=t2;
            t2=p2;

            last->next=t1;
            t1->prev=last;
            last=t1;
            t1=p1;
        }
    }

    if(t1)
    {
        last->next=t1;
        t1->prev=last;
    }

    if(t2)
    {
        last->next=t2;
        t2->prev=last;
    }

    return h1;
}
int main()
{
    Node *h1,*h2;
    h1=NULL;
    h2=NULL;
    int i,n;
    for(i=0;i<10;i++)
    {
        Node *ptr;
        ptr=create_Node((i+1));
        h1=insert_at_end(h1,ptr);

        ptr=create_Node((i+1)+10);
        h2=insert_at_end(h2,ptr);
    }

    display(h1);

    display(h2);

    h1=merge(h1,h2);

    display(h1);
}

