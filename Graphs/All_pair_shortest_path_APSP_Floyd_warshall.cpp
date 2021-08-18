#include<iostream>
#include<climits>

#define SIZE 100

using namespace std;

void APSP(int Cost[][SIZE],int n)
{
    int i,j,k,G[n][n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {   
            if(cost[i][j]!=0)
            G[i][j]=Cost[i][j];
            else
            G[i][j]=INT_MAX;
        }
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(G[i][k]==INT_MAX || G[k][j]==INT_MAX)
                continue;
                else if(G[i][j]>G[i][k]+G[k][j])
                {
                    G[i][j]=G[i][k]+G[k][j];
                }
            }
        }
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(G[i][j]<0)
            {
                cout<<"\nNegative Edge wait cycle detected\n\n";
                break;
            }
           
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int n,i,j;
    cout<<"Enter the Num of vertices : ";
    cin>>n;
    int Cost[SIZE][SIZE];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;i++)
        {
            cin>>Cost[i][j];
        }
    }

    APSP(Cost,n);
}