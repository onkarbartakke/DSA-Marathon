#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

//Graph based adjancey list approach
vector<int> ans;
int count = 1;
void Traverse(BinaryTree *root, unordered_map<int, vector<int>> &mp, unordered_map<int, bool> &visited)
{
    if (root == NULL)
        return;

    visited[root->value] = false;

    if (root->left)
    {
        count++;
        mp[root->value].push_back(root->left->value);
        mp[root->left->value].push_back(root->value);
    }

    if (root->right)
    {
        count++;
        mp[root->value].push_back(root->right->value);
        mp[root->right->value].push_back(root->value);
    }

    if (root->left)
        Traverse(root->left, mp, visited);

    if (root->right)
        Traverse(root->right, mp, visited);
}

void Find_at_dist_K(int target, unordered_map<int, vector<int>> &mp, int k, unordered_map<int, bool> &visited)
{
    if (k == 0)
    {
        ans.push_back(target);
        return;
    }

    vector<int> V = mp[target];
    int i;
    visited[target] = true;
    for (i = 0; i < V.size(); i++)
    {
        if (visited[V[i]] == false)
            Find_at_dist_K(V[i], mp, k - 1, visited);
    }

    return;
}
vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k)
{
    // Write your code here.
    ans.clear();
    unordered_map<int, vector<int>> mp;
    unordered_map<int, bool> visited;
    count = 1;
    Traverse(tree, mp, visited);
    Find_at_dist_K(target, mp, k, visited);

    return ans;
}


//Recursive Approach

class Node
{
    public:
        int data;
        Node* lchild;
        Node* rchild;
        Node(int d=0)
        {
            this->data=d;
            this->lchild=NULL;
            this->rchild=NULL;
        }
};

void print_subtree_nodes(Node *root, int k)
{
    if(root==NULL || k<0)
    return;

    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    
    print_subtree_nodes(root->lchild,k-1);
    print_subtree_nodes(root->rchild,k-1);
}

int print_nodes_at_k(Node *root, int key, int k)
{
    if(root==NULL)
    return -1;

    if(root->data==key)
    {
        print_subtree_nodes(root,k);
        return 0;
    }

    int dl=print_nodes_at_k(root->lchild,key,k);

    if(dl!=-1)
    {
        if(1+dl==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            print_subtree_nodes(root->rchild,k-dl-2);
        }
        return dl+1;
    }

    int dr=print_nodes_at_k(root->rchild,key,k);

    if(dr!=-1)
    {
        if(1+dr==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            print_subtree_nodes(root->lchild,k-dr-2);
        }
        return dr+1;
    }

    return -1;
}   

int main()
{
}