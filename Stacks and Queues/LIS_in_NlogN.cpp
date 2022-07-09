#include<bits/stdc++.h>

using namespace std;


int LIS_size(vector<int>&A)
{
    vector<int>si;

    for(int i = 0 ; i < A.size() ; i++)
    {
        if(si.empty() || A[i] > si.back())
        si.push_back(A[i]);
        else
        {
            int idx = lower_bound(si.begin(), si.end(), A[i]) - si.begin();
            si[idx] = A[i];
        }

    }

    return si.size();
}


int main()
{
    int n;
    cin>>n;

    vector<int>A(n);

    for(int i = 0 ; i < n ; i ++)
    cin>>A[i];

    int si = LIS_size(A);

    cout<<"\n"<<si;
}