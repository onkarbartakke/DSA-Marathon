#include<bits/stdc++.h>

using namespace std;

int Tsp(int mask, int pos, vector<vector<int>>&dp , int &allVisited, vector<vector<int>>&cost)
{
    if(mask == allVisited)
    return cost[pos][0];

    if(dp[mask][pos] != -1)
    return dp[mask][pos];

    int currAns = INT_MAX;
    for(int city = 0 ; city < cost.size() ; city ++)
    {
        int ops;
        if(mask & (1<<city)  == 0)
        {
            ops = cost[pos][city] + Tsp(mask | (1<<city) , city, dp, allVisited, cost);
        }

        currAns = min(currAns , ops);
    }
    
    return dp[mask][pos] = currAns;
}


int main()
{
    cout<<"Enter the num of cities : ";

    int n;

    cin>>n;

    vector<vector<int>>cost(n, vector<int>(n));

    cout<<"\nEnter the cost matrix : \n";
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        cin>>cost[i][j];
    }

    int pos = 0;
    int mask = 1;
    int allVisted = (1<<n) - 1;

    vector<vector<int>>dp(allVisted+1 , vector<int>(n,-1));


    cout<<Tsp(mask,pos,dp,allVisted,cost)<<"\n";
}