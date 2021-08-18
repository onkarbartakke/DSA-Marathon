#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int pos)
{
    if(pos == 0)
        return;

    Node* walk = head;
    for(int i = 1; i < pos; ++i)
    {
        walk = walk->next;
    }
    tail->next = walk;
}


bool detectLoop(Node* head)
{
    bool f=false;
    // your code here
    Node *fast,*slow;
    slow=head;
    fast=slow->next;
    
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        if(fast==NULL || slow==NULL)
        {
            f=false;
            break;
        }
        
        if(fast==slow)
        {
            f=true;
            break;
        }
    }
    
    return f;
}


int main()
{
    int n, num;
    cin >> n;
    Node *head = NULL, *tail;
    tail = head;
    if(n)
    {
        cin >> num;
        head = tail = new Node(num);
        for(int i = 0; i < n - 1; ++i)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        int pos;
        cin >> pos;
        loopHere(head, tail, pos);
    }
    if(detectLoop(head))
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }

    return 0;
}
