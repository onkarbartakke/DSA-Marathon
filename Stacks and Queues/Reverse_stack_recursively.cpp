#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>&st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }

    int tp=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(tp);
}

void reverse_stack(stack<int>&st)
{
    if(st.empty())
    return;

    int ele=st.top();
    st.pop();

    reverse_stack(st);
    insertAtBottom(st, ele);
}

int main()
{
    stack<int>st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverse_stack(st);

    cout<<st.top()<<"\n";
    st.pop();

    cout<<st.top()<<"\n";
    st.pop();

    cout<<st.top()<<"\n";
    st.pop();

    cout<<st.top()<<"\n";
    st.pop();

    cout<<st.top()<<"\n";
    st.pop();
}