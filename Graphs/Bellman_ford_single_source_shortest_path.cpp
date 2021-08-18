#include<iostream>
#include<vector>
#include<climits>

using namespace std;



class Edges
{
    public:
        int src;
        int dst;
        int wt;
};

void Bellman_ford_algo(vector<Edges>&edge, int E, int Vertices, int start)
{
    int i,j,k,u,v,wt;
    int parent[Vertices],value[Vertices];
    for(i=0;i<Vertices;i++)
    {
        value[i]=INT_MAX;
    }

    parent[start]=-1;
    value[start]=0;

    bool update=false;

    for(i=0;i<Vertices-1;i++)
    {
        update=false;
        for(j=0;j<E;j++)
        {
            u=edge[j].src;
            v=edge[j].dst;
            wt=edge[j].wt;

            if(value[u]!=INT_MAX && value[u]+wt<value[v])
            {
                value[v]=wt+value[u];
                parent[v]=u;
                update=true;
            }
        }

        if(update==false)
        break;
    }

    if(update==true)
    {
        update=false;
        for(j=0;j<E;j++)
        {
            u=edge[j].src;
            v=edge[j].dst;
            wt=edge[j].wt;

            if(value[u]!=INT_MAX && value[u]+wt<value[v])
            {
                value[v]=wt+value[u];
                parent[v]=u;
                update=true;
            }
        }

        if(update==true)
        cout<<"\nNegative cycle Exists in here\n";
    }


    cout<<"\n\n";

    for(i=0;i<Vertices;i++)
    {
        cout<<"U --> V :: "<<parent[i]<<" --> "<<i<<" Cost to reach "<<i<<" from source is "<<value[i]<<"\n";
    }
}

int main()
{
    int i,j,V,E;
    cout<<"Enter the Num of vertices : ";
    cin>>V;
    cout<<"\nEnter the Num of Edges : ";
    cin>>E;
    vector<Edges>edge(E);
    int src,dst,wt;

    cout<<"\nEnter edges in Source destination and Weight format : \n";
    for(i=0;i<E;i++)
    {
        cin>>edge[i].src;
        cin>>edge[i].dst;
        cin>>edge[i].wt;
    }

    Bellman_ford_algo(edge,E,V,0);
}