#include<iostream>
#include<queue>
#define SIZE 100
using namespace std;

void BFS(int G[][SIZE], int start ,int n)
{
    queue<int>qu;
    int u,v;
    int visited[n]={0};
    cout<<start<<" ";
    visited[start]=1;
    qu.push(start);
   
    while(!qu.empty())
    {
        u=qu.front();
        qu.pop();
       
        for(v=0;v<n;v++)
        {
            if(G[u][v]==1 && visited[v]==0)
            {
                cout<<v<<" ";
                visited[v]=1;
                qu.push(v);
            }
        }
    }
}

int main()
{
    int i,j,n;
    cout<<"Enter the Number of Vertices in Graph : ";
    cin>>n;

    int G[SIZE][SIZE];
    cout<<"Enter the Graph in form of adjency matrix (vertives start from 0) : \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>G[i][j];
        }
    }

    BFS(G,0,n);
}