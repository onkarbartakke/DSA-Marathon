
#include <bits/stdc++.h>

using namespace std;



int solve()
{
    long long int n;
    long long int cost = 0;
    cin >> n;
    vector<vector<long long int>> vec;
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    for (int i = 0; i < n; ++i)
    {
        long long int sz;
        cin >> sz;
        vector<long long int> v(sz);
       // cout<<"imput\n";
        for (long long int j = 0; j < sz; ++j)
        {
            cin>>v[j];
        }

        vec.push_back(v);
    }
    bool update=false;
    for (long long int i = 0; i < n; ++i)
    {
        long long int start = 0;
       // cout<<"\nIncreasing seq\n";
        for (long long int j = 0; j < vec[i].size() - 1; ++j)
        {
            if (vec[i][j] > vec[i][j + 1])
            {
                long long int a1=j-start+1;
                long long int a2=vec[i].size()-j-1;
                cost += min(a1,a2);
                pq.push(a1);
                update=true;
                //cout<<"pushing\n";
                start = j + 1;
            }
        }
        if(update)
        pq.push(vec[i].size()-start);


        if(!update)
        pq.push(vec[i].size());

        update=false;
    }

    

        
    while (pq.size() > 1)
    {
      //  cout<<"Heap\n";
        long long int a = pq.top();
       // cout<<a<<"\n";
        pq.pop();
        long long int b = pq.top();
       // cout<<b<<"\n";
        pq.pop();
        cost += (a + b);
        pq.push(a + b);
    }

    return cost;
}
int main()
{
    long long int t;
    cin >> t;
    for (long long int it = 1; it <= t; it++)
    {
        cout<<solve()<<"\n";

    } 
    return 0;
}