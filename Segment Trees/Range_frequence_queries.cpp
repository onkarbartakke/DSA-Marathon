#include <bits/stdc++.h>

using namespace std;

/*
Design a data structure to find the frequency of a given value in a given subarray.

The frequency of a value in a subarray is the number of occurrences of that value in the subarray.
*/

class RangeFreqQuery
{
    public:
    //     class Info
    //     {
    //       public:
    //       unordered_map<int,int>mp;

    //       Info(int val=-1)
    //       {
    //           mp[val]++;
    //       }
    //     };

    //     int n;
    //     vector<Info>seg;
    //     vector<int>a;

    //     void Build(int ind, int low, int high)
    //     {
    //         if(low==high)
    //         {
    //             seg[ind].mp[a[low]] = 1;
    //             return ;
    //         }

    //         int mid = (low+high) >>1;

    //         Build(2*ind+1,low,mid);
    //         Build(2*ind+2,mid+1,high);

    //         Info t;

    //         t = seg[2*ind+1];

    //         for(auto it : seg[2*ind+2].mp)
    //         {
    //             t.mp[it.first] += it.second;
    //         }

    //         seg[ind] = t;
    //     }

    unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int> &arr)
    {

        //         a = arr;
        //         n = arr.size();
        //         seg.resize(4*n);

        //         Build(0,0,n-1);

        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
    }

    //     int RangeQuery(int ind, int low, int high, int l, int r, int val)
    //     {
    //         if(low> r || high<l)
    //             return 0;

    //         if(low>= l && high<=r)
    //             return seg[ind].mp[val];

    //         int mid = (low+high) >> 1;
    //         return (RangeQuery(2*ind+1,low,mid,l,r,val) + RangeQuery(2*ind+2,mid+1,high,l,r,val));
    //     }
    int query(int left, int right, int value)
    {

        return upper_bound(mp[value].begin(), mp[value].end(), right) - lower_bound(mp[value].begin(), mp[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */