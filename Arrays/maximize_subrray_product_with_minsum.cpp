#include<bits/stdc++.h>

using namespace std;

void maxValue(vector<int>a)
{
    long long int n=a.size();
    long long int i,j,presum[n],l[n],r[n];

    presum[0]=a[0];
    for(i=1;i<n;i++)
    {
        presum[i]=presum[i-1]+a[i];
    }

    stack<long long >st;

    l[0]=-1;
    st.push(0);
    for(i=1;i<n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i])
        st.pop();

        if(!st.empty())
        l[i]=st.top();
        else 
        l[i]=-1;

        st.push(i);
    }


    stack<long long>stk;
    r[n-1]=n;
    for(i=0;i<n;i++)
    {
        while(!stk.empty() && a[stk.top()]>=a[i])
        {
            r[stk.top()]=i;
            stk.pop();
        }

        stk.push(i);

    }

    while(!st.empty())
    {
        r[stk.top()]=n;
        stk.pop();
    }

    long long max_product, temp_product;

    max_product=0;

    for(i=0;i<n;i++)
    {
        temp_product= a[i]*( presum[r[i]-1] - (l[i]==-1?0:presum[l[i]]));

        max_product=max(max_product,temp_product);
    }

    //cout<<max_product;

    return max_product;
    // cout<<"\n\n";
    /*
    for(i=0;i<n;i++)
    {
        cout<<l[i]<<" ";
    }

    cout<<"\n\n";
     for(i=0;i<n;i++)
    {
        cout<<r[i]<<" ";
    }
    */
}


int main()
{
      int n = 5;
    int arr[] = { 4,7,2,8,3};
 
    // Function call
    maxValue(arr, n);
}
