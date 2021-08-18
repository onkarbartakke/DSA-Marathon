#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int , vector<int>>pqmax;
priority_queue<int, vector<int> , greater<int> >pqmin;

void insert(int x)
{
    if(pqmax.size()==pqmin.size())
    {
        if(pqmax.size()==0)
        {
            pqmax.push(x);
        }
        else
        {
            if(x < pqmax.top())
            {
                pqmax.push(x);
            }
            else
            {
                pqmin.push(x);
            }
        }
    }
    else
    {
        if(pqmax.size() < pqmin.size())
        {
            if(x<=pqmax.top())
            {
                pqmax.push(x);
            }
            else
            {
                int temp=pqmin.top();
                pqmin.pop();
                pqmin.push(x);
                pqmax.push(temp);
            }
        }
        else
        {
            if(x>=pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                int temp=pqmax.top();
                pqmax.pop();
                pqmax.push(x);
                pqmin.push(temp);
            }
        }
    }
}

double Find_median()
{
    if(pqmax.size()==pqmin.size())
    {
        return (pqmax.top()+pqmin.top())/2.0;
    }
    else if(pqmax.size() > pqmin.size())
    return pqmax.top();
    else
    return pqmin.top();
} 

int main()
{
    int n,i,x;
    cout<<"\nEnter the num of elements : ";
    cin>>n;
    cout<<"\nEnter the Elements : \n";

    for(i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
        cout<<Find_median()<<"\n";
    }
}