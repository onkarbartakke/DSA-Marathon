#include <iostream>
#include <vector>
#include <queue>

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

Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> minheap;

    int i, j;
    Node *head, *tail;
    head = NULL;
    tail = NULL;

    for (i = 0; i < K; i++)
    {
        minheap.push({arr[i]->data, arr[i]});
    }

    while (!minheap.empty())
    {
        pair<int, Node *> tp = minheap.top();
        minheap.pop();

        int x = tp.first;

        if (head == NULL)
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            tail->next = new Node(x);
            tail = tail->next;
        }

        Node *p = tp.second;

        if (p->next != NULL)
        {
            p = p->next;
            minheap.push({p->data, p});
        }
    }

    return head;
}

int main()
{
}