#include<iostream>

using namespace std;



class Node
{
    public:
    int data;
    Node *next;

    Node(int d=0)
    {
        data=d;
        next=NULL;
    }
};

int getNthFromLast(Node *head, int n)
{
       // Your code here
    Node *p1,*p2;
    int i=0;
    
    p1=head;
    p2=head;
    
    while(i<n && p2!=NULL)
    {
        p2=p2->next;
        i++;
    }
    
    if(p2!=NULL)
    {
         while(p2)
        {
            p1=p1->next;
            p2=p2->next;
        }
    
        return p1->data;
    }
    if(p2==NULL)
    {
        if(i==n)
        return p1->data;
        else
        return -1;
    }
}

int main()
{

}
