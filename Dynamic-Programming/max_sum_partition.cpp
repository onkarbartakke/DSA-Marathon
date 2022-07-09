#include<bits/stdc++.h>

using namespace std;

int solve(int ind, vector<int>&v, int k, vector<int>&Dp)
{
    if(Dp[ind]!=-1)
    return Dp[ind];


    int maxi = INT_MIN , maxAns = INT_MIN, sum;

    int len = 0;
    for(int i = ind ; i < min(ind+k , v.size()) ; i++)
    {
        len++;
        maxi = max(maxi , v[i]);
        sum = maxi*len + solve(ind+1,v,k,Dp);

        maxAns = max(maxAns,sum);

    }

    return Dp[ind] = maxAns;
}
int MaxPartitionSum(vector<int>&V, int k)
{
    int ind = 0;
    int n = V.size();

    vector<int>Dp(n,-1);
    return solve(ind,V,k,Dp);
}
int main()
{
    int n;
    cin>>n;

    vector<int>V(n);

    for(int i = 0 ; i < n ; i++)
    cin>>V[i];

    int k;
    cin>>k;

    cout<<"\n\n"<<MaxPartitionSum(V,k);
}