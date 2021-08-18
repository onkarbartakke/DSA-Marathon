#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include<string>
#include<stack>
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

int FindIndex(int start , int end, string s)
{
    if(start>end)
    return -1;

    stack<char>st;

    for(int i=start;i<=end;i++)
    {
        if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')')
        {
            if(!st.empty() && st.top()=='(')
            {
                st.pop();

                if(st.empty())
                return i;
            }
        }
    }

    return -1;
}

Node* CreateTree(string s, int start, int end)
{
   if(start>end)
   return (NULL);

   if(s[start]!='(' && s[start]!=')')
   {
       Node *r=new Node(s[start]-'0');
   
        int index=-1;

        if(start+1<=end && s[start+1]=='(')
         index=FindIndex(start+1,end,s);

        if(index!=-1)
        {
            r->left=CreateTree(s,start+2,index-1);
            r->right=CreateTree(s,index+2,end-1);
        }

        return r;
   }

   return NULL;
}

void preorder(Node *r)
{
    if(r)
    {
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}

int main()
{
    cout<<"Enter the string : ";
    string s;
    cin>>s;

    Node *root=CreateTree(s,0,s.length()-1);
    cout<<"\n";
    preorder(root);
}