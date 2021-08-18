#include<iostream>
#include<vector>

using namespace std;

int get_comp(vector<vector<int>>&adjlst, int visited[], int curr)
{
    if(visited[curr])
    return 0;

    
    visited[curr]=1;
    int ans=1;
    for(auto i : adjlst[curr])
    {
        if(visited[i]==0)
        {

            ans+=get_comp(adjlst,visited,i);
        }
    }

    return ans;
}

int main()
{
    int i,j,v,e,x,y;

    cout<<"Enter the num of Vertices and Edges : ";
    cin>>v>>e;

    vector<vector<int>>adjlst(v);

    cout<<"\nEnter the Edges : ";

    for(i=0;i<e;i++)
    {
        cin>>x>>y;

        //x -- y
        adjlst[x].push_back(y);
        adjlst[y].push_back(x);
    }

    int visited[v]={0};
    vector<int>components;

    for(i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            int size=get_comp(adjlst,visited,i);
            components.push_back(size);
        }
    }
}