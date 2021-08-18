#include<iostream>
#include<stack>
#include<vector>
#include<limits>

using namespace std;


class Stack
{
    public:
    int minEle;
    stack<int>st;

    Stack()
    {
        minEle=INT_MAX;
    }

    void Push(int x)
    {
        if(x>=minEle)
        {
            st.push(x);
            return;
        }

        if(x<minEle)
        {
            st.push(2*x-minEle);
            minEle=x;
            return;
        }
    }

    int pop()
    {
        if(st.empty())
        return -1;

        int y=st.top();
        st.pop();

        if(y>=minEle)
        return y;

        if(y<minEle)
        {
            int x=minEle;
            minEle=2*minEle-y;
            return x;
        }
    }

    int getMin()
    {
        return minEle;
    }
};
int main()
{
    
}