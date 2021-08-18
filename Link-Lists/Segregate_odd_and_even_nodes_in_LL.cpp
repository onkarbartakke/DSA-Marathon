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



Node *divide(int N, Node *head)
{

    // code here
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp, *evenH, *evenT, *oddH, *oddT;

    temp = head;
    evenH = NULL;
    evenT = NULL;
    oddH = NULL;

    while (temp)
    {
        Node *p = temp->next;

        if (temp->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenH = temp;
                evenT = temp;
            }
            else
            {
                evenT->next = temp;
                evenT = temp;
            }
        }
        else
        {
            if (oddH == NULL)
            {
                oddH = temp;
                oddT = temp;
            }
            else
            {
                oddT->next = temp;
                oddT = temp;
            }
        }

        temp->next = NULL;

        temp = p;
    }

    if (evenT != NULL)
    {
        evenT->next = oddH;
        return evenH;
    }
    else
        return oddH;
}

int main()
{
}