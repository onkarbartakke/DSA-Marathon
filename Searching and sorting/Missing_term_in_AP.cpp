#include<iostream>
#include<algorithm>

using namespace std;

int Find_Missing(int a[], int n)
{
    int i,j,d,A,N;
    A=a[0];
    d=min(a[1]-a[0], a[2]-a[1]);

    int low,high,mid;
    low=0;
    high=n-1;
    
    while(low<=high)
    {
        mid=(low+high)/2;

        if(a[mid+1]-a[mid]!=d)
        return (a[mid]+d);

         N=mid+1;

         if(a[mid]==(A+(N-1)*d))
         low=mid+1;
         else
         {
            high=mid-1;
         }
    }

    return -1;
}

int main()
{
    int n,i,j;
    cout<<"Enter the num of terms : ";
    cin>>n;
    cout<<"\nEnter the n terms : \n";
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"\nMissing term is "<<Find_Missing(a,n);
}