#include<iostream>
#include<climits>

using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

int construct(BST *t, vector<int>&pre, int pos, int n, int left, int right)
{
	if(pos>=n || left>pre[pos] || right<pre[pos])
		return pos;
	
	if(t->value > pre[pos])
	{
		t->left=new BST(pre[pos]);
		pos++;
		pos=construct(t->left,pre,pos,n,left,t->value-1);
	}
	
	if(pos>=n || left>pre[pos] || right<pre[pos])
		return pos;
	

	
		t->right=new BST(pre[pos]);
		pos++;
		pos=construct(t->right,pre,pos,n,t->value,right);
		return pos;
	
}

BST *reconstructBst(vector<int> pre) {
  // Write your code here.
	int n=pre.size();
	
	if(n==0)
		return nullptr;
	
	if(n==1)
	{
		BST *t=new BST(pre[0]);
		return t;
	}
	else
	{
		BST *t=new BST(pre[0]);
		int pos=1;
		construct(t,pre,pos,n,INT_MIN,INT_MAX);
		return t;
	}
}
