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




Node *removeDuplicates(Node *head)
{
 // your code goes here
     Node *curr,*Next;
     curr=head;
     Next=curr->next;
     
     while(Next)
     {
         if(curr->data==Next->data)
         {
             curr->next=Next->next;
             Next->next=NULL;
             
             delete Next;
             
             Next=curr->next;
         }
         else
         {
             curr=curr->next;
             Next=Next->next;
         }
     }
     
     return head;
 
}

int main()
{
    
}