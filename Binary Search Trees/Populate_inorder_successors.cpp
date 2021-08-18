#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int d = 0)
    {
        data = d;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void populate(Node *root, Node **p)
{
    if (root)
    {
        populate(root->right, p);

        root->next = (*p);
        (*p) = root;

        populate(root->left, p);
    }
}
void populateNext(Node *root)
{
    //code here
    Node *p = NULL;
    populate(root, &p);
}

int main()
{
}