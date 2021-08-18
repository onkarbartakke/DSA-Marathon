#include<iostream>
#include <stack>

using namespace std;

void insert_reverse(stack<int>&st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    else
    {
        int top_ele=st.top();
        st.pop();
        insert_reverse(st,ele);
        st.push(top_ele);
    }

}

void reverse(stack<int>&st)
{
    if(!st.empty())
    {
        int temp;
        temp=st.top();
        st.pop();
        reverse(st);
        insert_reverse(st,temp);
    }   
}

void display(stack<int>st)
{
    cout<<"\n\n";

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    int i,n;
    cout<<"Enter the Number of ele : ";
    cin>>n;

    cout<<"\nEnter the elements in stack : ";

    stack<int>st;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }

    display(st);
    
    reverse(st);


    display(st);
}