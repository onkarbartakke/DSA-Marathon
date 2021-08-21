#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d=0)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int>ans;
    
    queue<Node*>qu;
    stack<int>st;
    
    qu.push(root);
    
    while(!qu.empty())
    {
        Node *t=qu.front();
        qu.pop();
        
        st.push(t->data);
        
        if(t->right)
        qu.push(t->right);
        
        if(t->left)
        qu.push(t->left);
    }
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    
    return ans;
}

int main()
{
    
}