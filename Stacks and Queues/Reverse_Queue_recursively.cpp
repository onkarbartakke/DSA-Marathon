#include<iostream>
#include<queue>

using namespace std;


void Reverse(queue<int>&qu)
{
    if(qu.empty())
    return;

    int ele=qu.front();
    qu.pop();
    Reverse(qu);
    qu.push(ele);
}
int main()
{
    int n,i,x;
    cout<<"Enter the num of elements in Qu : ";
    cin>>n;

    queue<int>qu;

    for(i=0;i<n;i++)
    {
        cin>>x;
        qu.push(x);
    }

    Reverse(qu);

    cout<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<qu.front()<<" ";
        qu.pop();
    }

}