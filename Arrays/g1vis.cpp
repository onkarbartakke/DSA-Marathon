#include<bits/stdc++.h>

using namespace std;

bool mycomp(pair<int,int>a, pair<int,int>b)
{
    if(a.first!=b.first)
    return a.first < b.first;
    else
    return a.second > b.second;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        vector<int>b(n);

        for(int i = 0 ; i< n ; i++)
        cin>>a[i];

        for(int i = 0 ; i < n ; i++)
        cin>>b[i];

        vector<pair<int,int>>v;

        for(int i = 0 ; i < n ; i++) 
        {
            v.push_back({a[i], b[i]});
        }

        sort(v.begin(), v.end() , mycomp);   // This will sort on base of v.first, If the v.first are same then it will sort on base of v.second

        int ans = n;

        int i = 0 , j = i+1;

        while(i<n && j<n)
        {
           j = i + 1;
           while(j<n)
           {
               if(v[i].first < v[j].first && v[i].second < v[j].second)
               {
                   ans -= (j - i );
                   i = j-1;
                   break;
               }
               j++;
           }

           i++;
        }

        cout<<ans<<"\n";
    }


}