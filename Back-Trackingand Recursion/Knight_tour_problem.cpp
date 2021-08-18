#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<int>>&sol, int x, int y)
{
    int n=sol.size();

    if(x<0 || y<0 || x>=n || y>=n || sol[x][y]!=-1)
    return false;
    else
    return true;
}

bool solveKT_Until(vector<vector<int>>&sol, int xMove[], int yMove[], int x, int y, int iMove)
{
    int i,nx,ny,n;
    n=sol.size();

    if(iMove==n*n)
    return true;

    for(i=0;i<8;i++)
    {
        nx=x+xMove[i];
        ny=y+yMove[i];

        if(isSafe(sol,nx,ny))
        {
            sol[nx][ny]=iMove;

            if(solveKT_Until(sol,xMove,yMove,nx,ny,iMove+1))
            return true;
            else
            sol[nx][ny]=-1; //Back Tracking
        }
    }

    return false;
}


bool solveKT(int n)
{
    vector<vector<int>>sol(n,vector<int>(n,-1));
    int i,j,x,y;
    int xMove[]={2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[]={ 1, 2, 2, 1, -1, -2, -2, -1};
    sol[0][0]=0;

    if(solveKT_Until(sol,xMove,yMove,0,0,1))
    {
        cout<<"\n\n";

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }

            cout<<"\n";
        }

        return true;
    }
    else
    return false;

}

int main()
{
    int n;
    cout<<"Enter the value of N for a N*N chess Board : ";
    cin>>n;

    if(solveKT(n))
    {
        cout<<"\nSolution Exists";   
    }
    else
    {
        cout<<"\nSolution Dosent Exits";
    }
}