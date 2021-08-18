#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    public:
    int N;
    stack<int>s1;
    stack<int>s2;

    Queue()
    {
        N=0;
    }

    void push(int x)
    {
        s2.push(x);
        N++;
        /*
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        */
    }

    int pop()
    {
        if(!s1.empty())
        {
            int x=s1.top();
            s1.pop();
            N--;
            return x;
        }
        else
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

            N--;
            int x=s1.top();
            s1.pop();
            return x;
        }
    }

    int front()
    {
        if(!s1.empty())
        {
            int x=s1.top();
            return x;
        }
        else
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

           
            int x=s1.top();
            return x;
        }   
    }

    int size()
    {
        if(N<0)
        return -1;
        else
        return N;
    }
};

int main()
{
    Queue qu;
    qu.push(1);  
    qu.push(2);  
    qu.push(3);  
    qu.push(4);   
    qu.push(5);
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n";  
}