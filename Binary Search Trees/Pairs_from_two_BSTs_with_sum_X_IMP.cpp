#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d = 0)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};


int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    if(root1==NULL || root2==NULL)
    return 0;
    
    stack<Node*>st1;
    stack<Node*>st2;
    
    Node *top1,*top2;
    int count=0;
    
    while(1)
    {
        while(root1!=NULL)
        {
            st1.push(root1);
            root1=root1->left;
        }
        
        while(root2!=NULL)
        {
            st2.push(root2);
            root2=root2->right;
        }
        
        
        if(st1.empty() || st2.empty())
        {
            return count;
        }
        
        top1=st1.top();
        top2=st2.top();
        
        if(top1->data + top2->data == x)
        {
            count++;
            root1=top1->right;
            root2=top2->left;
            
            st1.pop();
            st2.pop();
        }
        else if(top1->data + top2->data < x)
        {
            st1.pop();
            root1=top1->right;
        }
        else
        {
            st2.pop();
            root2=top2->left;
        }
    }
    
    return count;
}

int main()
{
    
}
