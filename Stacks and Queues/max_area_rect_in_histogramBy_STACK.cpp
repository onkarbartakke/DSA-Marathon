#include<bits/stdc++.h>

using namespace std;

int Max_area_rect(int hist[], int n)
{
    int left[n]={0},right[n]={0};
    int i;
    stack<int>st;

    for(i=0;i<n;i++)
    {
        if(st.empty())
        {
            left[i]=0;
           
        }
        else
        {
            while(!st.empty()  &&  hist[st.top()]>=hist[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                left[i]=0;
            }
            else
            {
                left[i]=st.top()+1;
            }
        }

        st.push(i);
    }
    while(!st.empty())
    st.pop();

    for(i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            right[i]=n-1;
        }
        else
        {
            while(!st.empty() && hist[st.top()]>=hist[i])
            st.pop();

            if(st.empty())
            right[i]=n-1;
            else
            {
                right[i]=st.top()-1;
            }
        }

        st.push(i);
    }

    int a,a1;
    a=0;
    a1=0;
    int area[n];
    for(i=0;i<n;i++)
    {
        a1=((right[i]-left[i])+1)*hist[i];
        area[i]=a1;
        a=max(a,a1);
    }

    cout<<"\n";
    cout<<"Left : ";
    for(i=0;i<n;i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<"\n";
    cout<<"Right : ";
    for(i=0;i<n;i++)
    {
        cout<<right[i]<<" ";
    }
    cout<<"\n";
    cout<<"Area : ";
    for(i=0;i<n;i++)
    {
        cout<<area[i]<<" ";
    }
    cout<<"\n";
    return a;
}

int main()
{
    int n,i;
    cout<<"Enter the num of rectangles in histogram : ";
    cin>>n;
    cout<<"\n\nEnter the Histogram : ";
    int hist[n];
    for(i=0;i<n;i++)
    {
        cin>>hist[i];
    }

    int a=Max_area_rect(hist,n);
    cout<<"\n"<<a;
}