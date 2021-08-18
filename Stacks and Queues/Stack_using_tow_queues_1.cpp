#include<iostream>
#include<queue>
using namespace std;
//Push Method costly
class Stack
{
    public:
    int N;
    queue<int>q1;
    queue<int>q2;
    queue<int>temp;

    Stack()
    {
        N=0;
    }

    void push(int x);
    int pop();
    int top();
    int size();
    
};

void Stack::push(int x)
{
    q2.push(x);
    N++;

    int ele;

    while(!q1.empty())
    {
       q2.push(q1.front());
       q1.pop();
    }

    temp=q1;
    q1=q2;
    q2=temp;
}

int Stack::pop()
{
    if(N<=0)
    return -1;


    int x=q1.front();
    q1.pop();
    N--;
    return x;
}

int Stack::top()
{
    if(N<=0)
    return -1;

    return q1.front();
}

int Stack::size()
{
    return N;
}


int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.pop()<<"\n";
    cout<<st.pop()<<"\n";
    st.push(4);
    cout<<st.pop()<<"\n";
}