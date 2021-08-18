#include<iostream>
#include<cmath>
#define SIZE 1000
using namespace std;

void heapify(int a[], int i, int n)
{
    int left,right,largest;
    left=2*i+1;
    right=2*i+2;

    if(left<n && a[i]<a[left])
    largest=left;
    else
    largest=i;

    if(right<n && a[largest]<a[right])
    largest=right;

    if(largest!=i)
    {
        int t;
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;

        heapify(a,largest,n);
    }
}

int Extract_max(int a[], int n)
{
    int i,j;
    int max=a[0];
    a[0]=a[n-1];
    a[n-1]=max;
    n=n-1;

    heapify(a,0,n);

    return max;
}

void Heapsort(int a[], int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        int k=Extract_max(a,n-i);
    }
}

void insert(int a[], int &n ,int m)
{
    a[n]=m;
    int i,t;
    n=n+1;

    i=n-1;
    int parent,child;
    child=i;
    parent=ceil((float)i/2)-1;
    while(i>0 && a[child]>a[parent])
    {
        t=a[child];
        a[child]=a[parent];
        a[parent]=t;

        i=parent; //ceil(i/2)-1
        child=i;
        parent=ceil((float)i/2)-1;
    }
}

void increase_key(int a[], int key, int val)
{
    if(a[key]>val)
    return;
    else
    {
        a[key]=val;
        int i=key;
        int child,parent;
        child=i;
        parent=ceil((float)i/2)-1;
        while(i>0 && a[child]>a[parent])
        {
            int t=a[child];
            a[child]=a[parent];
            a[parent]=t;

            i=parent; //ceil(i/2)-1
            child=i;
            parent=ceil((float)i/2)-1;
        }
    }
}

void decrease_key(int a[], int key, int val, int n)
{
    if(a[key]<val)
    return;
    else
    {
        a[key]=val;
        heapify(a,key,n);
    }
}

int main()
{
    int n,i;
    cout<<"Enter the num of elements : ";
    cin>>n;
    int a[SIZE];
    cout<<"\nEnter the Elements :  \n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int nonleaf=(n/2)-1;
    for(i=nonleaf;i>=0;i--)
    {
        heapify(a,i,n);
    }


    cout<<"\nHeapify array : \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }


    
    cout<<"\n";

    cout<<"Enter the element to be inserted : ";
    int m;
    cin>>m;
    insert(a,n,m);

    cout<<"\nHeapify array : \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }  


    Heapsort(a,n);

    cout<<"\nSorted: \n";

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}