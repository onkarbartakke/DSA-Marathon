#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int kth_largest_subarray(vector<int>&a , int n, int k)
{
    int i,j;
    vector<int>sum(n,a[0]);

    for(i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }

    priority_queue<int, vector<int> , greater<int> >qu;

    qu.push(sum[0]);

    for(i=1;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            int x=sum[j]-sum[i-1];

            if(qu.size()<k)
            qu.push(x);
            else
            {

                if(qu.top()<x)
                {
                    qu.pop();
                    qu.push(x);
                }
            }
        }
    }

    return qu.top();
}

int main()
{
    int n,i;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int>a(n);
    cout<<"\nEnter the elements : \n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int k=kth_largest_subarray(a,n);

    cout<<"\n"<<k;
}