#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

void BST_to_sortedLL(Node *root, Node **head)
{
    if(root==NULL)
    return;

    BST_to_sortedLL(root->right,head);

    root->right=(*head);

    if(*head!=NULL)
    {
        (*head)->left=NULL;
    }

    (*head)=root;
    BST_to_sortedLL(root->left,head)
}

void sortedLL_to_minHeap(Node *head, Node **root)
{
    (*root)=head;
    queue<Node*>qu;

    Node *parent;

    qu.push(head);

    head=head->right;

    while(head)
    {
        Node *parent=qu.front();
        qu.pop();
        parent->right=NULL;

        Node *leftChild=head;
        head=head->right;

        leftChild->right=NULL;
        qu.push(leftChild);
        parent->left=leftChild;

        if(head)
        {
            Node *rightChild=head;
            head=head->right;

            rightChild->right=NULL;
            qu.push(rightChild);

            parent->right=rightChild;
        }
    }
}
void BST_to_minHeap(Node *root)
{
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL)
    return;

    Node *head=NULL;

    BST_to_sortedLL(root,&head);

    root=NULL;
    sortedLL_to_minHeap(head, *root);
}
int main()
{

}