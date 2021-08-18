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

int getMiddle(Node *head)
{
   // Your code here
   Node *fast,*slow;
   fast=head;
   slow=head;
   
   while(fast!=NULL)
   {
       fast=fast->next;
       
       if(fast!=NULL)
       {
           fast=fast->next;
           slow=slow->next;
       }
   }
   
   return slow->data;
}




int main()
{

}