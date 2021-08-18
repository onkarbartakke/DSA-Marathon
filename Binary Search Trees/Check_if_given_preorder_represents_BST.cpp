#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d=0)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

bool isBST(vector<int>&pre)
{
    int n,i,j;
    n=pre.size();

    if(n==0 || n==1)
    return true;

    stack<int>st;

    int root=INT_MIN;

    for(i=0;i<n;i++)
    {
        if(pre[i]<root)
        return false;


        while(!st.empty() && st.top()< pre[i])
        {
            root=st.top();
            st.pop();
        }

        st.push(pre[i]);
    }

    return true;
}

int main()
{

}