#include<bits/stdc++.h>

using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n)
{

    vector<long long> ans(arr.size());
    // Your code here
    stack<long long> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }
    }

    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }

    return ans;
}


int main()
{
    
}