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

int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
	int val=tree->value;
	
	
	int d=abs(tree->value-target);
	
	while(tree)
	{
		int diff=abs(tree->value-target);
		if(diff<d)
		{
			d=diff;
			val=tree->value;
		}
		
		
		
		if(tree->value > target)
		{
			tree=tree->left;
		}
		else
		{
			tree=tree->right;
		}
	}
	
  return val;
}

int main()
{

}