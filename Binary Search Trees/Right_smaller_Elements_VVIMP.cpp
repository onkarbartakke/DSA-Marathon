#include<iostream>
#include<vector>

using namespace std;


/* Q..
Write a function to count number of smaller elements on right of each element in an array. Given an unsorted array arr[] 
of distinct integers, construct
 another array countSmaller[] such that countSmaller[i] contains count of smaller elements on right 
 side of each element arr[i] in array.
*/


class splBST
{
	public:
	int data;
	int idx;
	int leftSubTreeSize;
	int numSmallerAtInsertTime;
	splBST *left;
	splBST *right;
	
	splBST(int d, int i, int numsmaller=0)
	{
		data=d;
		idx=i;
		numSmallerAtInsertTime=numsmaller;
		leftSubTreeSize=0;
		left=NULL;
		right=NULL;
	}
	
};
//Approach 1
// Avg time O(NLogN), worst O(N*N);

void insert(splBST *r, int i, int val,int numsmaller)
{
	if(r==NULL)
		return;

	if(val < r->data)
	{
		(r->leftSubTreeSize)++;
		
		if(r->left)
		{
			insert(r->left,i,val,numsmaller);
		}
		else
		{
			
			r->left=new splBST(val,i,numsmaller);
			return;
		}
	}
	else
	{
		numsmaller+=(r->leftSubTreeSize);
		if(val > r->data)
		{
			numsmaller++;
		}
		
		if(r->right)
		{
			insert(r->right,i,val,numsmaller);
		}
		else
		{
			r->right=new splBST(val,i,numsmaller);
		}
	}
}

void Traverse(splBST *r, vector<int>&ans)
{
	if(r==NULL)
		return;
	
	ans[r->idx]=r->numSmallerAtInsertTime;
	Traverse(r->left,ans);
	Traverse(r->right,ans);
}
vector<int> rightSmallerThan(vector<int> array) {
  // Write your code here.
	int n=array.size();
	vector<int>ans(n);
	if(array.size()==0)
  return ans;
	
	if(array.size()==1)
	{
		vector<int>v;
		v.push_back(0);
		return v;
	}
	int last=array.size()-1;
	splBST *root=new splBST(array[last],last,0);
	
	for(int i=last-1;i>=0;i--)
	{
		insert(root,i,array[i],0);
	}
	
	Traverse(root,ans);
	
	return ans;
}


int main()
{

}