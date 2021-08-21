#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<stack>
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

vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int>ans;
	stack<Node*>curr;
	stack<Node*>next;
	
	bool LeftToRight=true;
	
	curr.push(root);
	
	while(!curr.empty())
	{
	    Node *temp=curr.top();
	    curr.pop();
	    
	    ans.push_back(temp->data);
	    
	    if(LeftToRight)
	    {
	        if(temp->left)
	        next.push(temp->left);
	        
	        if(temp->right)
	        next.push(temp->right);
	    }
	    else
	    {
	        if(temp->right)
	        next.push(temp->right);
	        
	        if(temp->left)
	        next.push(temp->left);
	    }
	    
	    if(curr.empty())
	    {
	        LeftToRight=!LeftToRight;
	        
	        stack<Node*>st;
	        st=curr;
	        curr=next;
	        next=st;
	    }
	}
	
	return ans;
}

int main()
{
    
}