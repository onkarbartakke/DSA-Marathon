#include<iostream>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
	int height;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value)
	{ 
		this->value = value; 
		height=0;
	}
};
bool ans=true;
int calHeight(BinaryTree *root)
{
	if(root==NULL)
		return 0;
	
	if(root->left==NULL && root->right==NULL)
	{
		root->height=1;
		return 1;
	}
	int left=0,right=0;
	if(root->height==0)
	{
		left=calHeight(root->left);
		right=calHeight(root->right);
		
		if(abs(left-right)>1)
		{
			ans=false;
		}
		
		if(left>right)
			root->height=left+1;
		else
			root->height=right+1;
	}
	
	return root->height;
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
  // Write your code here.
	ans=true;
	tree->height=calHeight(tree);
  return ans;
}

int main()
{
    
}