#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int color=1;
    set<int>Edges;
};

bool graphColoring(int m, int V, vector<Node>&nodes)
{
    bool visited[V+1];
    memset(visited,false,V+1);
    queue<int>qu;
    int maxColor=1;
    for(int i=0;i<V;i++)
    {
        if(visited[i])
        continue;

        visited[i]=true;
        qu.push(i);

        while(!qu.empty())
        {
            int t=qu.front();
            qu.pop();

            for(auto it=nodes[t].Edges.begin();it!=nodes[t].Edges.end();it++)
            {
                if(nodes[t].color==nodes[*it].color)
                {
                    nodes[*it].color++;
                }

                maxColor=max(maxColor,max(nodes[t].color,nodes[*it].color));

                if(maxColor>m)
                return false;

                if(!visited[*it])
                {
                    visited[*it]=true;
                    qu.push(*it);
                }
            }
        }
    }

    return true;
}

int main()
{
    /*m colours given for graph of V vertices,
    graph[i][j]=1 if there exist a edge from i to j

    No two adjacent vertices must have same colour
    determine whether graph coloring possible or not
    */
   int V,m,i,j,k;
   bool graph[101][101];
   cout<<"Enter thr num of Vertices : ";
   cin>>V;
   cout<<"\nEnter the Graph : \n";

   for(i=0;i<V;i++)
   {
       for(j=0;j<V;j++)
       {
           cin>>k;
           if(k)
           graph[i][j]=true;
           else
           graph[i][j]=false;
       }
   }

    vector<Node>nodes(V+1);
    for(i=0;i<V;i++)
    {
        for(j=i+1;j<V;j++)
        {
            if(graph[i][j])
            {
                nodes[i].Edges.insert(j);
                nodes[j].Edges.insert(i);
            }
        }
    }
   cout<<"\nEnter the num of colours : ";
   cin>>m;

   if(graphColoring(m,V,nodes))
   cout<<"\nPOssible";
   else
   cout<<"\nNot Possible";
}