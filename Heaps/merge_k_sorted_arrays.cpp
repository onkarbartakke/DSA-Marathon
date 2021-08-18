#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int i,j,k;
    cout<<"Enter the num of arrays : ";
    cin>>k;

    vector< vector<int> >a(k);

    cout<<"\nEnter in K arrays one by one, 1st the size then the elemnts : \n";
    for(i=0;i<k;i++)
    {
        cout<<"\nEnter the SIZE : ";
        int size;
        cin>>size;

        cout<<"\nEnter the Elements : \n";

        a[i]=vector<int>(size);

        for(j=0;j<size;j++)
        {
            cin>>a[i][j];
        }

        
    }

    vector<int>idx(k,0);

    vector<int>ans;

    priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > >heap;

    for(i=0;i<k;i++)
    {
        heap.push({a[i][0],i});
    }

    int val,x;

    while(!heap.empty())
    {
        pair<int,int>pi=heap.top();
        heap.pop();

        val=pi.first;
        x=pi.second;

        ans.push_back(val);
        
        if(idx[x]+1 < a[x].size())
        {
            heap.push({a[x][idx[x]+1],x});
        }

        idx[x]+=1;
    }

    cout<<"\nSorted K \n";
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}