#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m,k;
        int i,j;
        cin>>n>>m>>k;

        vector<vector<char>>grid(n,vector<char>(m));

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }

        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='.')
                continue;
                else if(grid[i][j]=='*')
                {
                    grid[i][j]='#';
                    check(grid,k);
                }
            }
        }
    }
}