#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void pixel_change(long int **p,long int x,long int y,long int k,long int sr,long int n,long int m)
{
    if(x<0 || y<0 || x>=n || y>=m || p[x][y]!=sr)
    {
        return;
    }
    else
    {
        p[x][y]=k;
        pixel_change(p,x+1,y,k,sr,n,m);
        pixel_change(p,x-1,y,k,sr,n,m);
        pixel_change(p,x,y+1,k,sr,n,m);
        pixel_change(p,x,y-1,k,sr,n,m);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long int n,m,i,j,x,y,k;
        cin>>n>>m;
        long int **p;
        p=new long int*[n];
        for(i=0;i<n;i++)
        {
            p[i]=new long int[m];
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>p[i][j];
            }
        }
        
        
        cin>>x>>y>>k;
        long int sr=p[x][y];
        pixel_change(p,x,y,k,sr,n,m);
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<p[i][j]<<" ";
            }
        }
        
        cout<<"\n";
    }
	return 0;
}