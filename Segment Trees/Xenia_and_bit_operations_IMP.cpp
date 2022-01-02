#include<bits/stdc++.h>

using namespace std;


void Build(vector<int>&arr , vector<int>&seg , int low, int high, int ind, bool orr)
{
    if(low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low+high) >> 1;

    Build(arr,seg,low,mid,2*ind+1,!orr);
    Build(arr,seg,mid+1,high,2*ind+2,!orr);

    if(orr)
    seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else
    seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];

    return;
}

void Update(int ind, vector<int>&seg, int low, int high, int i, int val, bool orr)
{
    if(low == high)
    {
        seg[ind] = val;
        return;
    }

    int mid = (low+high)>>1;

    if(i<=mid)
    Update(2*ind+1,seg,low,mid,i,val,!orr);
    else
    Update(2*ind+2,seg,mid+1,high,i,val,!orr);


    if(orr)
    seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else
    seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];

    return;
    
}


int main()
{
    int n,i;
    cin>>n;
    int num = pow(2,n);

    vector<int>arr(num);

    for(i=0;i<num;i++)
    cin>>arr[i];

    vector<int>seg(4*num);

    bool orr = true;

    if(n%2==0)
    Build(arr,seg,0,num-1,0,!orr);
    else
    Build(arr,seg,0,num-1,0,orr);


    // Tage te input queries
}