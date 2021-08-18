#include<iostream>

using namespace std;


void BubbleSort(int a[], int n)
{
    int i,j,flag=0,temp;

    for(i=0;i<n-1;i++)
    {
        flag=1;
        for(j=0;j<n-1-i;j++)
        {

            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=0;
            }
        }

        if(flag==1)
        break;
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

    BubbleSort(a,n);
    cout<<"\n\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }   
}