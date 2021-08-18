#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;
void DFS(int u, vector<vector<int>>adjlst,vector<bool>&visited,stack<int>&st);
vector<int> Toposort(int V, int E, vector<vector<int>>&adjlst);


int main()
{
    int i,j,v,e,x,y;
    
    cout<<"Enter num of Vertics and Edges : ";
    cin>>v>>e;

    vector< vector<int>>adjlst(v+1);

    cout<<"\nEnter the Edges : \n";
    int incoming[v+1]={0};
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        //x --> y

        adjlst[x].push_back(y);
        incoming[y]++;
    }

    vector<int>ans;
    queue<int>qu;

    for(i=1;i<=v;i++)
    {
        if(incoming[i]==0)
        {
            qu.push(i);
        }
    }

    cout<<"\n\n";
     vector<int>::iterator it;
    while(!qu.empty())
    {
        int x;
        x=qu.front();
        qu.pop();
        ans.push_back(x);

        vector<int>::iterator it;

        for(it=adjlst[x].begin();it!=adjlst[x].end();it++)
        {
            incoming[*it]--;

            if(incoming[*it]==0)
            {
                qu.push(*it);
            }
        }
    }

    for(it=ans.begin();it!=ans.end();it++)
    {
        cout<<*it<<" ";
    }


    cout<<"\n*****************************************\n";

    vector<int>ans2=Toposort(v,e,adjlst);

    for(i=0;i<ans2.size();i++)
    {
        cout<<ans2[i]<<" ";
    }
}

//Approach 2


void DFS(int u, vector<vector<int>>adjlst,vector<bool>&visited,stack<int>&st)
{
    if(visited[u]==false)
    {
        visited[u]=true;

        vector<int>v=adjlst[u];

        for(int i=0;i<v.size();i++)
        {
            if(visited[v[i]]==false)
            {
                DFS(v[i],adjlst,visited,st);
            }
        }

        st.push(u);
    }
}

vector<int> Toposort(int V, int E, vector<vector<int>>&adjlst)
{
    int i,j,k;
    vector<bool>visited(V+1,false);
    vector<int>ans;
    stack<int>st;

    for(i=1;i<=V;i++)
    {
        if(visited[i]==false)
        {
            DFS(i,adjlst,visited,st);
        }
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}    