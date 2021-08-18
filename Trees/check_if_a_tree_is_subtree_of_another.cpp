#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
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

//Approach 1

bool isIdentical(Node *T, Node *S)
{
    if (T == NULL && S == NULL)
        return true;

    if (T == NULL || S == NULL)
        return false;

    return ((T->data == S->data) && (isIdentical(T->left, S->left)) && isIdentical(T->right, S->right));
}
bool isSubTree(Node *T, Node *S)
{
    // Your code here
    // if(T==NULL && S==NULL)
    // return true;

    // if(T==NULL || S==NULL)
    // return false;

    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    if (isIdentical(T, S))
        return true;

    return (isSubTree(T->left, S) || isSubTree(T->right, S));
}

//Approach 2, O(N^2) time but only works for single digit node values

void inorder(Node *r, char in[], int &i)
{
    if (r == NULL)
    {
        in[i] = '$';
        i++;
        return;
    }
    inorder(r->left, in, i);
    in[i] = 48 + r->data;
    i++;
    inorder(r->right, in, i);
}

void preorder(Node *r, char pre[], int &i)
{
    if (r == NULL)
    {
        pre[i] = '$';
        i++;
        return;
    }

    pre[i] = 48 + r->data;
    i++;
    preorder(r->left, pre, i);
    preorder(r->right, pre, i);
}
bool isSubTree(Node *T, Node *S)
{
    // Your code here
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    int MAX = 100009;
    char inT[MAX], preT[MAX];
    char inS[MAX], preS[MAX];

    int m = 0, n = 0;
    inorder(T, inT, m);
    inorder(S, inS, n);

    inT[m] = '\0';
    inS[n] = '\0';

    if (strstr(inT, inS) == NULL)
        return false;

    m = 0;
    n = 0;

    preorder(T, preT, m);
    preorder(S, preS, n);

    preT[m] = '\0';
    preS[n] = '\0';

    if (strstr(preT, preS) != NULL)
        return true;
    else
        return false;
}

//To overcome above flaw

void inorder(Node * root, vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-5);
        return ;
    }
    inorder(root->left,v);
   
    v.push_back(root->key);
    inorder(root->right,v);
}

void preorder(Node * root, vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-5);
        return ;
    }
    v.push_back(root->key);
    preorder(root->left,v);
    preorder(root->right,v);
}

bool issubtre( vector<int> parent ,vector<int> child)
{
    string s1="";
    string s2="";
    
    for(ll i=0;i<parent.size();i++)
      s1+= to_string(parent[i]);
    for(ll i=0;i<child.size();i++)
      s2+= to_string(child[i]);
     
     if( s1.find(s2) != -1)
       return true;
       
       return false;
}

bool isSubtree(Node*  T1 ,Node * T2)
{
   vector<int> int1;
   vector<int> int2;
   vector<int> pret1;
   vector<int> pret2;
   
   inorder(T1,int1);
   inorder(T2,int2);
   preorder(T1,pret1);
   preorder(T2,pret2);
  return issubtre(int1,int2) && issubtre(pret1,pret2); 
 }

 int main()
 {
     
 }