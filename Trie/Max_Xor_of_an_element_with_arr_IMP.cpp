#include<bits/stdc++.h>

using namespace std;


class Node
{
    public:
    Node *links[2];

    Node()
    {
        links[0] = NULL;
        links[1] = NULL;
    }
};

class Trie
{
    public:
    Node *root;

    Trie()
    {
        root = new Node;
    }

    void insert(int x)
    {
        Node *n = root;

        for(int i = 31; i >= 0 ; i--)
        {
            int b = (x>>i)&1;

            if(n->links[b] == NULL)
            n->links[b] = new Node;
            
            n = n->links[b];
        }
    }


    int maxXOR(int x)
    {
        int ret = 0;
        Node *n = root;

        for(int i = 31; i>=0 ; i--)
        {
            int b = (x>>i)&1;

            if(n->links[1-b])
            {
                ret += pow(2,i);
                n = n->links[1-b];
            }
            else
            n = n->links[b];
            
        }

        return ret;
    }

};


bool static cmp(vector<int>&a , vector<int>&b)
{
    if(a[1] < b[1])
    return true;
    else
    return false;
}



vector<int> MaxXOR_elements(vector<int>&arr, vector<vector<int>>&Queries)
{
    int n,i,q;
    n = arr.size();
    q = Queries.size();

    sort(arr.begin(),arr.end());

    sort(Queries.begin() , Queries.end() , cmp);
    cout<<"\n----------\nSorted\n--------\n";
    Trie T;

    vector<int>ans(q);

    int ind = 0;
  
    for(i=0;i<q;i++)
    {
        int xi = Queries[i][0];
        int ai = Queries[i][1];
        int qnd = Queries[i][2];

        while(ind < n && arr[ind]<=ai)
        {
            T.insert(arr[ind]);
            cout<<"\n----------\nInserted : "<<arr[ind]<<"\n--------\n";
            ind++;
        }

        if(ind == 0)
        ans[qnd] = -1;
        else
        ans[qnd] = T.maxXOR(xi);
    }

    return ans;
}

int main()
{
    int n,i,q;

    cout<<"Enter the number of elements in Arr : ";
    cin>>n;

    vector<int>arr(n);

    cout<<"\nEnter the ELements : \n";

    for(i= 0 ; i < n;i++)
    cin>>arr[i];

    cout<<"\nEnter the number of Queries : ";
    cin>>q;

    vector<vector<int>>Queries(q,vector<int>(3));

    cout<<"\nEnter the Queries (xi and ai): \n";

    for(i=0;i<q;i++)
    {
        cin>>Queries[i][0]>>Queries[i][1];
        Queries[i][2] = i;
    }

    vector<int>ans = MaxXOR_elements(arr,Queries);

    cout<<"\n\n Ans : - \n\n";

    for(auto it : ans)
    cout<<it<<" ";
}