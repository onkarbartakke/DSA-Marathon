#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
They are N candies and N people and a NxN Likes array if Like[i][j] = 1 means ith person likes jth candy
if Like[i][j] = 0 means ith person will not like jth candy and will not have it

Find total number ways to distrubute candy such that everyone gets candy of their like


Like = {{1,1,1} ,
        {1,0,1} , 
        {1,1,1}}

coding Ninjas DP 
*/

long long solve(vector<vector<int>>likes)
{
    int n = likes.size();

    vector<int>dp((1<<n) + 1);

    dp[(1<<n) - 1] = 1;  // corresponds to this 111111 where all candies are assigned to some person so ways = 1

    for(int mask = (1<<n) - 2 ; mask >= 0 ; mask--)
    {
        //Count set bits that is how many candies are assigned

        int cnt = 0;

        for(int i = 31 ; i >= 0 ; i--)
        {
            if((mask>>i)&1)
            cnt++;
        }

        //cnt num of persons have got the candy not check in available num of candies if the next person can get 
        //cndy he likes

        for(int i = 0 ; i < n ; i++)
        {
            if(likes[cnt][i] && !((mask>>i )& 1)) //2nd condition is to check that in current mask ith candy is not assigned to anyone
            {
                dp[mask] += dp[mask |  (1<<i)];
            }
        }
    }

    return dp[0];

}


int main()
{

}