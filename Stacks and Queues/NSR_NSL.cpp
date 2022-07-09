#include<bits/stdc++.h>

using namespace std;


void Find_NSR_NSL(vector<int>&a, int n)
{
    vector<int>nsl(n), nsr(n);

    nsl[0] = -1;
    nsr[n-1] = -1;

    stack<int>st;

    for(int i = 0 ; i < n ; i++)
    {
        while(!st.empty() && a[st.top()] > a[i])
        {
            int idx = st.top();
            st.pop();

            nsr[idx] = a[i];
        }
        st.push(i);
    } 

    while(!st.empty())
    {
        int i = st.top();
        st.pop();

        nsr[i] = -1;
    }

    for(int i = n -1 ; i >= 0 ; i--)
    {
        while(!st.empty() && a[st.top()] > a[i])
        {
            int idx = st.top();
            st.pop();

            nsl[idx] = a[i];
        }
        st.push(i);
    }


    while(!st.empty())
    {
        int i = st.top();
        st.pop();

        nsl[i] = -1;
    }


    cout<<"\n\n";

    for(auto it : a)
    cout<<it<<" ";

    cout<<"\n\n";

    cout<<"NSR : \n";
    for(auto it : nsr)
    cout<<it<<" ";

    cout<<"\nNSL : \n";
    for(auto it : nsl)
    cout<<it<<" ";
}


int main()
{
    int n;
    cin>>n;

    vector<int>a(n);

    for(int i = 0 ; i < n ; i++)
    cin>>a[i];

    Find_NSR_NSL(a,n);
}