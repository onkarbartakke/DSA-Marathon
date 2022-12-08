#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

vector<long long>dp(10002,-1);


long long FormPartitions(string s, int idx)
{
    if(idx >= s.length())
    return 0;

    if(dp[idx]!=-1)
    return dp[idx];


    int zeros = 0;
    long long ops = 0, operations = INT_MAX;
    for(int i = idx ; i < s.length() ; i = i + 2)
    {
        if(s[i] == '0')
        zeros++;

        if(s[i+1] == '0')
        zeros++;

        ops = min(zeros , (i+1-idx+1 - zeros));

        ops = (ops%mod) +  FormPartitions(s,i+2) % mod;

        operations = min(ops,operations);
    }

    return dp[idx] = operations % mod;
}


vector<int> vikingSubstring(string s)
{
    vector<int>ans(2);

    int n = s.length();

    long B,K;

    long long B = FormPartitions(s,0);

    cout<<B<<"\n";

    return ans;
}
int main()
{

}