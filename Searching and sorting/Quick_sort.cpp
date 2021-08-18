#include<iostream>

using namespace std;

int partition(int a[] , int low, int high)
{
    int i,j,k;
    int x=a[low];

    i=low;
    j=high;

    while(i<j)
    {
        while(a[i]<=x && i<=j)
        {
            if(a[i]==x)
            k=i;

            i++;
        }

        while(a[j]>x && i<=j)
        {
            j--;
        }

        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    if(j<low)
    j++;

    a[k]=a[j];
    a[j]=x;

    return j;   
}

void QuickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);

        QuickSort(a,low,pi-1);
        QuickSort(a,pi+1, high);
    }
}

int main()
{
    int n,i,j;
    cout<<"Enter the num of elements : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the Elements of Array : \n";

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    QuickSort(a,0,n-1);
    cout<<"\n\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }   
}