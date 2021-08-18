#include<iostream>

using namespace std;



void SelectionSort(int a[], int n)
{
    int i,j,m,temp;

    for(i=0;i<n-1;i++)
    {
        m=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[m])
            m=j;
        }

        temp=a[m];
        a[m]=a[i];
        a[i]=temp;

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

    SelectionSort(a,n);
    cout<<"\n\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }   
}