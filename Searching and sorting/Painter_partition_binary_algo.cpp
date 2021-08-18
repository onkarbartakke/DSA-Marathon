#include<iostream>
#include<algorithm>

using namespace std;

int feasible(int board[], int n, int limit)
{
    int p=1;
    int len=0;

    for(int i=0;i<n;i++)
    {
        len+=board[i];
        if(len>limit)
        {
            p++;
            len=board[i];
        }
    }

    return p;
}

int painterpartition(int board[], int n, int m)
{
    int k, low,  high,mid;
    low=board[0];
    for(int i=0;i<n;i++)
    {
        low=max(low,board[i]);
        high+=board[i];
    }

    while(low<high)
    {
        mid=(low+high)/2;
        int p=feasible(board,n,mid);
        if(p<=m)
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }
    }

    return low;
}

int main()
{
    int n,i;
    cout<<"Enter the num of painters : ";
    cin>>n;

    int board[n];
    cout<<"\nEnter the lenghth of boards : \n";

    for(i=0;i<n;i++)
    {
        cin>>board[i];
    }
    int m;
    cout<<"\nEnter the num of painters :  ";
    cin>>m;

    int ans=painterpartition(board,n,m);
    cout<<"\n"<<ans;
}