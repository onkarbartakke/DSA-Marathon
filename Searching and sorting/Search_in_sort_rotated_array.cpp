#include<iostream>

using namespace std;


int Bin_search(int a[], int key, int left, int right)
{
    if(left>right)
    return -1;

    int mid=(left+right)/2;

    if(a[mid]==key)
    return mid;

    if(a[left]<=a[mid])
    {
        if(a[left]<=key && key<=a[mid])
        return Bin_search(a,key,left,mid-1);
        else
        return Bin_search(a,key,mid+1,right);
    }
    else
    {
        if(a[mid]<=key && key<=a[right])
        return Bin_search(a,key,mid+1,right);
        else
        return Bin_search(a,key,left,mid-1);
    }
}

int main()
{
    int n,i;
    cout<<"Enter the num of elements in array : ";
    cin>>n;
    cout<<"\nEnter the Array Elements : ";
    int a[n];
    for(i=0;i<n;i++)
    {

        cin>>a[i];
    }

    cout<<"\nEnter the key to be searched : ";
    int key;
    cin>>key;

    int pos=Bin_search(a,key,0,n-1);

    cout<<"\nEle found at index : "<<pos;
}