 #include<iostream>
#include<vector>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};


void Traverse(BinaryTree *root, vector<int>&v)
{
	if(root==NULL)
		return;
	
	if(root->left==NULL && root->right==NULL)
	{
			v.push_back(root->value);
			return;
	}
	
	Traverse(root->left,v);
	Traverse(root->right,v);
}

bool compareLeafTraversal(BinaryTree *tree1, BinaryTree *tree2) {
  // Write your code here.
	if(tree1==NULL && tree2==NULL)
		return true;
	
	if(tree1==NULL || tree2==NULL)
		return false;
  vector<int>v1;
	vector<int>v2;
	
	Traverse(tree1,v1);
	Traverse(tree2,v2);
	
	if(v1==v2)
		return true;
	else
		return false;
}
