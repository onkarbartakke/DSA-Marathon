#include<iostream>
#include<climits>
#define SIZE 100
using namespace std;


int find(int u, int set[])
{
    int x=u;
    while(set[x]>0)
    {
        x=set[x];
    }

    return x;
}

void Myunion(int u, int v, int set[])
{
    if(set[u]>set[v])
    {
        set[v]=set[v]+set[u];
        set[u]=v;
    }
    else if(set[u]<set[v])
    {
        set[u]=set[u]+set[v];
        set[v]=u;
    }
    else if(set[u]==set[v])
    {
        if(u>v)
        {
            set[u]=set[u]+set[v];
            set[v]=u;
        }
        else
        {
            set[v]=set[v]+set[u];
            set[u]=v;
        }
    }
}

void Kruskals_spaningT(int Edges[][SIZE], int n, int e)
{
    int include[e]={0},i,j,k,min,u,v,set[n];
    int ans[2][n-1];

    for(i=0;i<n;i++)
    {
        set[i]=-1;
    }

    i=0;

    while(i<n-1)
    {
        min=INT_MAX;
        for(j=0;j<e;j++)
        {
            if(include[e]==0 && Edges[2][j]<min)
            {
                min=Edges[2][j];
                k=j;
            }
        }

        u=Edges[0][k];
        v=Edges[1][k];

        int x=find(u,set);
        int y=find(v,set);

        if(x!=y)
        {
            ans[0][i]=u;
            ans[1][i]=v;
            Myunion(x,y,set);
            i++;
        }

        include[k]=1;
    }

    cout<<"\n";
    for(i=0;i<n-1;i++)
    {
        cout<<"(  "<<ans[0][i]<<" , "<<ans[1][i]<<" )\n";
    }
}


int main()
{
    int n,i,j,k;
    cout<<"Enter the total num of vertices : ";
    cin>>n;
    int cost[SIZE][SIZE];

    cout<<"\nEnter the cost matrix : \n";

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }

    int Edges[3][SIZE];
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(cost[i][j]>0)
            {
                Edges[0][k]=i;
                Edges[1][k]=j;
                Edges[2][k]=cost[i][j];
                k++;
            }
        }
    }

    Kruskals_spaningT(Edges,n,k);
}