#include<iostream>
#include <stack>
#define SIZE 100
using namespace std;

void DFS1(int G[][SIZE],int start, int n)
{
    int u,v;
    stack<int>st;
    int visited[n]={0};
    
    u=start;
    cout<<u<<" ";
    st.push(u);
    visited[u]=1;
    while(!st.empty())
    {
        u=st.top();
        st.pop();

        for(v=0;v<n;v++)
        {
            if(G[u][v]==1 && visited[v]==0)
            {
                cout<<v<<" ";
                visited[v]=1;
                st.push(v);
                u=v;
                v=0;
            }
        }
       
    }
    
}

void DFS2(int G[][SIZE], int start, int n)
{
    int u,v;
    static int visited[SIZE]={0};

    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;
        for(v=0;v<n;v++)
        {
            if(G[start][v]==1)
            DFS2(G,v,n);
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
    cout<<"\n\n";
    DFS1(G,0,n);
    cout<<"\n\n";
    DFS2(G,0,n);
}