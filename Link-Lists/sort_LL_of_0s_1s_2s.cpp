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

Node *segregate(Node *head)
{

    // Add code here
    int count[3] = {0};

    Node *t = head;

    while (t)
    {
        count[t->data]++;

        t = t->next;
    }

    t = head;

    while (t)
    {
        if (count[0] > 0)
        {
            t->data = 0;
            count[0]--;
        }
        else if (count[1] > 0)
        {
            t->data = 1;
            count[1]--;
        }
        else if (count[2] > 0)
        {
            t->data = 2;
            count[2]--;
        }

        t = t->next;
    }

    return head;
}

int main()
{
}
