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

void Inorder(vector<int>&a, vector<int>&V, int index, int n)
{
    if(index>=n)
    return;

    Inorder(a,V,2*index+1,n);

    V.push_back(a[index]);

    Inorder(a,V,2*index+2,n);
}


int Minswaps(vector<int>&V, int n)
{
    int i,j,k,count,ans=0;

    vector< pair<int,int> >S(n);

    for(i=0;i<n;i++)
    {
        S[i].first=V[i];
        S[i].second=i;
    }

    sort(S.begin(),S.end());

    vector<bool>visited(n);
    memset(visited,false,n);

    for(i=0;i<n;i++)
    {
        if(visited[i] || S[i].second==i)
        continue;

        j=i;
        count=0;

        while(!visited[j])
        {
            visited[j]=true;

            j=S[j].second;
            count++;
        }

        if(count>1)
        ans=ans+(count-1);
    }

    return ans;
}


int main()
{
    int i,j,n,x;
    cout<<"Enter the Number of Nodes : ";
    cin>>n;

    cout<<"\nEnter the Array Representation of Trees : \n";
    vector<int>a(n);

    for(i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }

    vector<int>V;

    Inorder(a,V,0,n);

    cout<<"Min swaps required for conversion of BT to BST are : "<<Minswaps(V,n);   
}
