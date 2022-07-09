#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,l,p,n;
        cin>>n;
        vector< pair<int,int> >V(n);
        
        for(i=0;i<n;i++)
        {
            cin>>V[i].first>>V[i].second;
        }

        cin>>l>>p;

        for(i=0;i<n;i++)
        {
            V[i].first=l-V[i].first;
        }

        sort(V.begin(),V.end());

        priority_queue<int, vector<int> >maxheap;
        int d=0;
        int count=0;
        bool flag=0;
        int curr=p;
        for(i=0;i<n;i++)
        {
            if(curr>=l)
            break;

            while(curr<V[i].first)
            {
                if(maxheap.empty())
                {
                    flag=1;
                    break;
                }
                else
                {
                    count++;
                    curr+=maxheap.top();
                    maxheap.pop();
                }
            }

            if(flag)
            break;

            maxheap.push(V[i].second);
        }

        if(flag)
        {
            cout<<"-1\n";
            continue;
        }

        while(!maxheap.empty() && curr<l)
        {
            curr+=maxheap.top();
            count++;
            maxheap.pop();
        }

        if(curr<l)
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            cout<<count<<"\n";
        }
    }
}
