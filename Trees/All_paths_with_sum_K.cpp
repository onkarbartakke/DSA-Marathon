#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include<unordered_set>
#include<unordered_map>

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


vector<vector<int>>ans;

void KsumPathUntil(Node *root, vector<int>&path, int k)
{
    if(root==NULL)
    return;

    path.push_back(root->data);

    if(root->left);
    KsumPathUntil(root->left,path,k);

    if(root->right)
    KsumPathUntil(root->right,path,k);

    vector<int>v;

    int sum=0;

    for(int j=path.size()-1;j>=0;j--)
    {
        sum=sum+path[j];
        v.insert(v.begin(),path[j]);

        if(sum==k)
        {
            ans.push_back(v);
        }
    }

    path.pop_back();
}


void KsumPath(Node *root,int k)
{
    if(root == NULL)
    return;

    vector<int>path;
    KsumPathUntil(root,path,k);
}

int main()
{

}