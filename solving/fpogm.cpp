#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


void Traverse(vector<vector<long long int>>&v, int x, int y)
{
    if(x<0 || y<0)
        return;
    
    if(x+2 < 1e9 && y+1 <1e9)
        v[x+2][y+1] = min(v[x+2][y+1] , 1+v[x][y]);
    
    if(x+2< 1e9 && y-1 >=0)
         v[x+2][y-1] = min(v[x+2][y-1] , 1+v[x][y]);
    
    if(x-2>=0 && y+1 <1e9)
        v[x-2][y+1] = min(v[x-2][y+1] , 1+v[x][y]);
    
    if(x-2>=0 && y-1 >=0)
         v[x-2][y-1] = min(v[x-2][y-1] , 1+v[x][y]);
    
    if(x+1 < 1e9 && y-2>=0)
        v[x+1][y-1] = min(v[x+1][y-2] , 1+v[x][y]);
    
    if(x+1<1e9 && y+2< 1e9)
        v[x+1][y+2] = min( v[x+1][y+2] , 1+v[x][y]);
    
    if(x-1 >= 0 && y-2>=0)
        v[x-1][y-1] = min(v[x-1][y-2] , 1+v[x][y]);
    
    if(x-1>=0 && y+2< 1e9)
        v[x-1][y+2] = min( v[x-1][y+2] , 1+v[x][y]);
    
    Traverse(v,x+2,y+1);
    //Traverse(v,x+2,y-1);
   // Traverse(v,x-2,y+1);
    //Traverse(v,x-2,y-1);
    
    Traverse(v,x+1,y+2);
    //Traverse(v,x-1,y)
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<vector<long long int>>v(1e9 , vector<long long int>(1e9, INT_MAX));
   v[0][0] = 0;
    Traverse(v,0,0);
        
    long int t;
    cin>>t;
    
    while(t--)
    {
        long long int x,y;
        cin>>x>>y;
        
        cout<<v[x][y]<<"\n";
    }
    return 0;
}