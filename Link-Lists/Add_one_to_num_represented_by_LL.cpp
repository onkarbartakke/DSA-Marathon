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

int Add(Node *head)
{
    if (head == NULL)
        return 0;

    if (head->next == NULL)
    {
        int carry;
        carry = (head->data + 1) / 10;
        head->data = (head->data + 1) % 10;

        return carry;
    }

    int c1 = Add(head->next);

    if (c1 == 0)
        return 0;

    int carry = (head->data + c1) / 10;
    head->data = (head->data + c1) % 10;

    return carry;
}
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    Node *t = head;

    if (head->next == NULL)
    {
        if (head->data + 1 <= 9)
        {
            (head->data)++;
            return head;
        }
        else
        {
            Node *p = new Node(1);
            p->next = head;
            head->data = 0;
            return p;
        }
    }

    int carry = Add(head->next);

    if (carry == 0)
        return head;

    else if (carry + head->data <= 9)
    {
        head->data += carry;
        return head;
    }
    else
    {
        int d1, d2;
        d2 = (head->data + carry) % 10;
        d1 = (head->data + carry) / 10;

        Node *h = new Node(d1);
        h->next = head;
        head->data = d2;

        return h;
    }
}

int main()
{
}