#include<iostream>
#include<stack>

using namespace std;

void sorted_insert(stack<int>&st, int ele)
{
    if(st.empty() || ele>=st.top())
    {
        st.push(ele);
        return;
    }

    int tp=st.top();
    st.pop();

    sorted_insert(st,ele);
    st.push(tp);

}
void Sort(stack<int>&st)
{
    if(st.size()==0)
    return;

    int ele=st.top();
    st.pop();
    Sort(st);
    sorted_insert(st,ele);
}
int main()
{
    int n,i,x;
    cout<<"Enter the num og elements: ";
    cin>>n;

    cout<<"\nEnter the Elements : \n";
    stack<int>st;
    for(i=0;i<n;i++)
    {
        cin>>x;
        st.push(x);
    
    }
    Sort(st);
    cout<<"\n\n";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}