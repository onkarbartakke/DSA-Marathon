#include<bits/stdc++.h>

using namespace std;

long long int two_sum(vector<long long int>&v, long long int s)
{
    long long int i,j,count=0;

    unordered_map<long long int, long long int>mp;

    for(i=0;i<v.size();i++)
    {
        
       mp[v[i]]++;
    }

    for(auto it : mp)
    {
        
        long long int n1,n2;
        n1 = it.first;
        n2 = s - n1;
        if(n1==n2)
        {
            long long int m = it.second;
            count+=((m*(m-1))/2);
        }
        else if(mp.find(n2)!=mp.end())
        {
            long long int m1,m2;
            m1 = it.second;
            m2 = mp[n2];
            count+=(m1*m2);

            mp.erase(n1);
            mp.erase(n2);
        }
    }

    return count;
}
int main()
{
    long long int n,i,s;
    cin>>n;
    cin>>s;
    vector<long long int>v(n);

    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }

    long long int ns = two_sum(v,s);

    cout<<"\n\n"<<ns;
}