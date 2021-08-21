#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<map>
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
void Traverse(Node* root, int d, map<int, vector<int>> &mp)
{
    if(root)
    {
        mp[d].push_back(root->data);
        
        if(root->left)
        Traverse(root->left,d+1,mp);
        
        if(root->right)
        Traverse(root->right,d,mp);
    }
}
vector<int> diagonal(Node *root)
{
   // your code here
   map<int, vector<int> >mp;
   
   Traverse(root,0,mp);
   vector<int>ans;
   for(auto it : mp)
   {
       vector<int>v=it.second;
       
       for(auto itr: v)
       {
           ans.push_back(itr);
       }
   }
   
   return ans;
}

int main()
{
    
}