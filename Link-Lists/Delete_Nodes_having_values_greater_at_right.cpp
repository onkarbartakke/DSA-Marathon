#include <iostream>

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


Node *compute(Node *head)
{
    // your code goes here
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = compute(head->next);

    if (head->data < curr->data)
    {
        head->data = curr->data;
        head->next = curr->next;
    }

    return head;
}

int main()
{
}