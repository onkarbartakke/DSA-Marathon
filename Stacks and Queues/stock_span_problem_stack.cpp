#include <iostream>
#include <string.h>
typedef int item;

using namespace std;

class stack
{
    private:
        int top;
        int size;
        item *s;
    public:
        stack(int s);
        void display();
        bool isEmpty();
        bool isFull();
        item  givetop();
        item  pop();
        void push(item x);
        item peek(int pos);
};

stack::stack(int si)
{
    size=si;
    top=-1;
    s=new item[size];
}

bool stack::isEmpty()
{
    if(top==-1)
    return true;
    else
    return false;
}

bool stack::isFull()
{
    if(top==size-1)
    return true;
    else
    return false;
}

item stack::givetop()
{
    if(isEmpty())
    {
        cout<<"INVALID\n";
        return -1;
    }
    else
    return s[top];
}

item stack::peek(int pos)
{
    if(top-pos+1<0)
    {
        cout<<"INVALID\n";
        return -1;
    }
    else
    {
        return s[top-pos+1];
    }
}

item stack::pop()
{
    if(isEmpty())
    {
        cout<<"INVALID\n";
        return -1;
    }
    else
    {
        item x=s[top];
        top--;
        return x;
    }
}

void stack::push(item x)
{
    if(isFull())
    {
        cout<<"INVALID\n";
    }
    else
    {
        top++;
        s[top]=x;
    }
}

void stack::display()
{
    int x=top;
    cout<<"\n";
    while(x>=0)
    {
        cout<<s[x]<<"\n";
        x--;
    }
    cout<<"\n\n";
    
}


int main()
{
    int n,i;
    cout<<"Enter the num of days : ";
    cin>>n;
    cout<<"\n\nEnter the stock price for n days : ";
    int price[n];
    for(i=0;i<n;i++)
    {
        cin>>price[i];
    }

    int span[n];
    stack s(n+1);
    for(i=0;i<n;i++)
    {
        while (!(s.isEmpty()) && price[s.givetop()]<=price[i])
        {
            s.pop();
        }

        if(s.isEmpty())
        {
            span[i]=i+1;
        }
        else
        {
            span[i]=i- s.givetop();
        }
        s.push(i);
    }

    cout<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<span[i]<<" ";
    }
}