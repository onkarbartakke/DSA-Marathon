#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int Trapped_RainWater(vector<int>&a, int n)
{
    stack<int>st;
    int i,j;
    int ans=0;
    for(i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()]<a[i])
        {
            int curr=st.top();
            st.pop();

            if(st.empty())
            {
                break;
            }
            else
            {
                int len=i-st.top()-1;
                int ht=min(a[i], a[st.top()])-a[curr];
                ans=ans+(len*ht);
            }
        }

        st.push(i);
    }
 
    return ans;
}

int main()
{
    int n,i,j;
    cout<<"Enter the num of boxes : ";
    cin>>n;
    vector<int>height(n);
    cout<<"\nEnter the Heights of Boxes : \n";
    for(i=0;i<n;i++)
    {
        cin>>height[i];
    }

    cout<<"\nTrapped Rainwater is : "<<Trapped_RainWater(height,n);
}