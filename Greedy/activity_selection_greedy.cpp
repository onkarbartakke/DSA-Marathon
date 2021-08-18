#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool mycomp(vector<int>&a, vector<int>&b)
{
    return a[1]<b[1];
}

int main()
{
    int n,i,j,start,count,end;
    cout<<"Enter num of activities : ";
    cin>>n;
    vector<vector<int>>V(n);
    cout<<"\nEnter start and end of n activites on separate lines : \n";

    for(i=0;i<n;i++)
    {
        // cin>>start;
        // cin>>end;
        // V.push_back({start,end});
        // cin>>V[i][0]>>V[i][1];
        vector<int>a(2);
        cin>>a[0];
        cin>>a[1];
        V[i]=a;
        
    }

    sort(V.begin(),V.end(),mycomp);

    count=1;
    end=V[0][1];

    for(i=1;i<n;i++)
    {
        if(V[i][0]>=end)
        {
            count++;
            end=V[i][1];
        }    
    }

    cout<<"\n"<<count;
}