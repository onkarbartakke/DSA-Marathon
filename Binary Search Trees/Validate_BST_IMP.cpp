#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

class BST
{
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

	if (tree->value < minVal || tree->value >= maxVal)
		return false;

	if (tree->left)
	{
		if (!validateBstHelper(tree->left, minVal, tree->value))
			return false;
	}

	if (tree->right)
	{
		if (!validateBstHelper(tree->right, tree->value, maxVal))
			return false;
	}

	return true;
}
bool validateBst(BST *tree)
{
	// Write your code here.
	return validateBstHelper(tree, INT_MIN, INT_MAX);
}

// Another approach covering edge cases of INT_MIN and INT_MAX

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
	public:
	bool isValidBST(TreeNode *root, TreeNode *minNode = NULL, TreeNode *maxNode = NULL)
	{

		if (root == NULL)
			return true;

		if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
			return false;

		if (root->left)
		{
			if (!isValidBST(root->left, minNode, root))
				return false;
		}

		if (root->right)
		{
			if (!isValidBST(root->right, root, maxNode))
				return false;
		}

		return true;
	}
};
int main()
{
}
