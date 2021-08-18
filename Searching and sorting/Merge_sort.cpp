#include<iostream>

using namespace std;

void Mergeself(int a[], int low, int mid, int high)
{
    int i,j,k;
    int help[high-low+1];

    k=0;
    i=low;
    j=mid+1;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            help[k++]=a[i++];
        }
        else
        {
            help[k++]=a[j++];
        }
    }

    while(i<=mid)
    {
        help[k++]=a[i++];
    }

    while(j<=high)
    {
        help[k++]=a[j++];
    }

    i=low;
    k=0;
    while(i<=high)
    {
        a[i++]=help[k++];
    }
}

void MergeSort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);

        Mergeself(a,low,mid,high);
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

    MergeSort(a,0,n-1);
    cout<<"\n\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }   
}