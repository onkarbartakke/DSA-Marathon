#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Node
{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int d=0)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
};


class Stack
{
    public:
    int size;
    Node *Head;
    Node *Tail;
    Node *mid;
    
    Stack()
    {
        Head=NULL;
        Tail=NULL;
        mid=NULL;
        size=0;
    }
 
    void push(int x)
    {
        if(Head==NULL)
        {
            Head=new Node(x);
            Tail=Head;
            mid=Head;
            size++;
        }
        else
        {
            Node *t=new Node(x);
            Tail->next=t;
            t->prev=Tail;
            Tail=t;
            if(size%2==0)
            {
                mid=mid->next;
            }
            size++;
        }
    }

    int pop()
    {
       if(size<=0)
       return -1;
    
        int x;
       if(size==1)
       {
           x=Tail->data;
           delete Tail;
           Head=NULL;
           Tail=NULL;
           mid=NULL;
           size--;
           return  x;
       }
       else
       {
           if(size%2==1)
           {
               mid=mid->prev;
           }
           x=Tail->data;
           Node *t=Tail;
           Tail=Tail->prev;
           delete t;
           size--;
           return x;
       }
    }

    int Size()
    {
        return size;
    }

    int findMid()
    {
        return mid->data;
    }

    int deleteMid()
    {
        if(size<=0)
        return -1;
        int x;
        if(size==1)
        {
            x=Head->data;
            delete Head;
            Head=Tail=mid=NULL;
            size--;
            return x;
        }
        else if(size==2)
        {
            x=Head->data;
            Node *t=Head;
            Head=Head->next;
            t->next=NULL;
            Head->prev=NULL;
            delete t;
            mid=Head;
            size--;
            return x;
        }
        else
        {
            Node *t=mid;
            x=t->data;
            mid->prev->next=mid->next;
            mid->next->prev=mid->prev;
            if(size%2)
            {
                mid=t->prev;
            }
            else
            {
                mid=t->next;
            }
            t->next=NULL;
            t->prev=NULL;

            size--;
            return x;
        }
    }
                          
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<"\n"<<st.findMid()<<"\n";
    cout<<"\n"<<st.deleteMid()<<"\n";
    cout<<"\n"<<st.deleteMid()<<"\n";
}