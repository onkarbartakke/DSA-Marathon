#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin>>n;

    vector<int>a(n);
    for(int i  = 0 ;  i < n ; i++)
    {
        cin>>a[i];
    }

    vector<int>jumps(n,INT_MAX);

    vector<int>pos(n,-1);

    jumps[0] = 0;

    for(int i = 1 ; i < n ; i++)
    {
        jumps[i] = INT_MAX;
        for(int j = 0 ; j < i ; j++)
        {
            if(j+a[j] >= i && jumps[j]!=INT_MAX)
            {
                if(jumps[j]+1 < jumps[i])
                {
                    jumps[i] = jumps[j]+1;
                    pos[i] = j;
                }
            }
        }
    }


    int sum = a[n-1];

    int k = pos[n-1];

    while(k>=0)
    {
        sum += a[k];
        k = pos[k];
    }

    if(jumps[n-1] == INT_MAX)
    cout<<"-1\n";
    else
    cout<<sum<<" "<<jumps[n-1]<<"\n";
}