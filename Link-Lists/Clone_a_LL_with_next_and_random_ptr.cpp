#include <iostream>
#include <map>

using namespace std;

class Node
{   public:
    int data;
    Node *next;
    Node *arb;

    Node(int d = 0)
    {
        data = d;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head)
{
    // Your code here
    map<Node *, Node *> mp;
    Node *h = NULL;
    Node *temp, *t;

    temp = head;

    while (temp)
    {
        Node *p = new Node(temp->data);
        p->arb = temp;

        mp[temp] = temp->next;

        if (h == NULL)
        {
            h = p;
            t = p;
        }
        else
        {
            t->next = p;
            t = p;
        }
        Node *q = temp;
        temp = temp->next;
        q->next = p;
    }

    Node *curr = h;

    while (curr)
    {
        curr->arb = (curr->arb->arb) ? (curr->arb->arb->next) : (curr->arb->arb);
        curr = curr->next;
    }

    temp = head;
    while (temp)
    {
        temp->next = mp[temp];
        temp = temp->next;
    }
    return h;
}

int main()
{
    
}