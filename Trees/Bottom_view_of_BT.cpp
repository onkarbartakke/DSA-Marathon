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

vector <int> bottomView(Node *root)
{
   // Your Code Here
   map<int,int>mp;
   queue<pair<Node*,int>>qu;
   
   int hd;
   Node *p;
   qu.push({root,0});
   
   while(!qu.empty())
   {
       p=qu.front().first;
       hd=qu.front().second;
       
       mp[hd]=p->data;
       
       if(p->left)
       qu.push({p->left,hd-1});
       
       if(p->right)
       qu.push({p->right,hd+1});
       
       
       qu.pop();
   }
   
   vector<int>ans;
   
   for(auto it : mp)
   ans.push_back(it.second);
   
   return ans;
}

int main()
{
    
}