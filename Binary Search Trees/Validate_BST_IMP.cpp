#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;


class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};


bool validateBstHelper(BST *tree, int minVal, int maxVal)
{
	//if(tree==NULL)
		//return true;
	
	if(tree->value < minVal || tree->value >= maxVal)
		return false;
	
	if(tree->left)
	{
		if(!validateBstHelper(tree->left,minVal,tree->value))
			return false;
	}
	
	if(tree->right)
	{
		if(!validateBstHelper(tree->right,tree->value,maxVal))
			return false;
	}
	
	return true;
}
bool validateBst(BST *tree) {
  // Write your code here.
  return validateBstHelper(tree, INT_MIN, INT_MAX);
}

int main()
{
    
}
