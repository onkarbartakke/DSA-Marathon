#include<iostream>

using namespace std;


int get_count(Node *h)
{
    if(h==NULL)
    return 0;
    
    return 1+get_count(h->next);
}


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int c1,c2;
    
    c1=get_count(head1);
    c2=get_count(head2);
    
    Node *h1,*h2;
    
    if(c1>c2)
    {
        h1=head1;
        h2=head2;
    }
    else
    {
        h1=head2;
        h2=head1;
    }
    
    int d=abs(c1-c2);
    
    int i=0;
    while(i<d)
    {
        h1=h1->next;
        i++;
    }
    
    while(h1!=NULL && h2!=NULL)
    {
        if(h1==h2)
        {
            return h1->data;
        }
        else
        {
            h1=h1->next;
            h2=h2->next;
        }
    }
}

int main()
{
    
}