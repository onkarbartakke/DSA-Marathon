#include<iostream>

using namespace std;

void Prod_array(int a[], int n)
{
    int ans[n];
    int i;
    ans[0]=1;
    for(i=1;i<n;i++)
    {
        ans[i]=ans[i-1]*a[i-1];
    }
    int temp=a[n-1];
    for(i=n-2;i>=0;i--)
    {
       ans[i]=ans[i]*temp;

       temp=temp*a[i];
    }

    cout<<"\n\n";

    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main()
{
    int n,i,j;
    cout<<"Enter the Num of Elements : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the Elements : \n";

    for(i=0;i<n;i++)
    cin>>a[i];


    Prod_array(a,n);
}