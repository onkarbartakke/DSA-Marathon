#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include<unordered_set>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char d )
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

string isdup(Node *root,unordered_set<string>&hash)
{
    string s="";
    
    if(root==NULL)
    {
        s=s+'$';
        return s;
    }
    
    string lstr=isdup(root->left,hash);
    
    if(lstr.compare(s)==0)
    return s;
    
    string rstr=isdup(root->right,hash);
    
    if(rstr.compare(s)==0)
    return s;
    
    s=s+(root->data)+lstr+rstr;
    
    if(s.length()>3 &&  hash.find(s)!=hash.end())
    {
        return "";
    }
    
    hash.insert(s);
    
    return s;
}


bool dupSub(Node *root)
{
     //your code here
     if(root==NULL)
     return false;
     unordered_set<string> hash;
     string lstr=isdup(root->left,hash);
     string s="";
     
     if(lstr.compare(s)==0)
     return true;
     
     string rstr=isdup(root->right,hash);
     if(rstr.compare(s)==0)
     return true;
     
     return false;
}

int main()
{
    
}