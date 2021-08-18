#include<iostream>


using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

bool isAncestor(BST *src , BST *dst)
{
	if(src==NULL)
		return false;
	
	while(src!=NULL)
	{
		if(src->value==dst->value)
			return true;
		
		if(src->value < dst->value)
		{
			src=src->right;
		}
		else
		{
			src=src->left;
		}
	}
	
	return false;
}
bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
  // Write your code here.
	
	if(isAncestor(nodeOne,nodeTwo) && isAncestor(nodeTwo,nodeThree))
		return true;
	
	if(isAncestor(nodeThree,nodeTwo) && isAncestor(nodeTwo,nodeOne))
		return true;
	

  return false;
}

int main()
{
    
}