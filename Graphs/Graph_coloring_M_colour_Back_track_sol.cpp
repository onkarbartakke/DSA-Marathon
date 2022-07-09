#include<iostream>
#include<vector>

using namespace std;


bool isSafe(bool graph[][101], int colour[], int V, int vertex)
{
    int i,j;
    for(i=0;i<V;i++)
    {
        if(graph[vertex][i] && colour[i]==colour[vertex])
        return false;
        
    }
    
    return true;
}

bool graphColoringUntil(bool graph[][101], int m, int V, int vertex, int colour[])
{
    if(vertex==V)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        colour[vertex]=c;
        if(isSafe(graph,colour,V,vertex))
        {
            if(graphColoringUntil(graph,m,V,vertex+1,colour)==true)
            return true;
        }
        
        colour[vertex]=0; //BackTrack
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int colour[V]={0};
    
    return graphColoringUntil(graph,m,V,0,colour);
}

int main()
{
    /*m colours given for graph of V vertices,
    graph[i][j]=1 if there exist a edge from i to j

    No two adjacent vertices must have same colour
    determine whether graph coloring possible or not
    */
   int V,m,i,j;
   bool graph[101][101];
   cout<<"Enter thr num of Vertices : ";
   cin>>V;
   cout<<"\nEnter the Graph : \n";
    int k;
   for(i=0;i<V;i++)
   {
       for(j=0;j<V;j++)
       {
           cin>>k;
           if(k)
           graph[i][j]=true;
       }
   }

   cout<<"\nEnter the num of colours : ";
   cin>>m;

   if(graphColoring(graph,m,V))
   cout<<"\nPOssible";
   else
   cout<<"\nNot Possible";
}