#include<bits/stdc++.h>

using namespace std;

int minCoinsRec(vector<int>&coins , int m, int V)
{
    if(V==0)
    return 0;

    int res = INT_MAX;

    for(int i=0; i<m;i++)
    {
        if(coins[i] <= V)
        {
            int sub_res = minCoinsRec(coins,m,V-coins[i]);

            if(sub_res!=INT_MAX && sub_res +1 < res)
            res = sub_res + 1;
        }
    }

    return res;
}

int minCoinsDP(vector<int>&coins , int m ,int V)
{
    vector<int>tabel(V+1,INT_MAX);

    tabel[0] = 0;

    for(int i = 1; i<=V; i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>=coins[j])
            {
                int sub_res = tabel[i - coins[j]];

                if(sub_res!=INT_MAX && sub_res + 1 < tabel[i])
                tabel[i] = sub_res + 1;
            }
        }
    }

    return tabel[V];
}
int main()
{
    int V,m;

    cout<<"Enter the number of coins : ";
    cin>>m;

    vector<int>coins(m);

    cout<<"\n\nEnter the coins : ";

    for(int i=0; i< m ; i++)
    cin>>coins[i];


    cout<<"\nEnter the value : ";
    cin>>V;

    cout<<"\n\nMin coins by Recursion is "<<minCoinsRec(coins,m,V);

     cout<<"\n\nMin coins by DP is "<<minCoinsDP(coins,m,V);
}