#include<iostream>

using namespace std;
#define N 1e5+3
int Help[(int)N];
void Merge(int a[], int l ,int m , int h)
{
    int i,j,k;

    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
        {
            Help[k++]=a[i++];
        }
        else
        {
            Help[k++]=a[j++];
        }
    }

    while(i<=m)
    Help[k++]=a[i++];

    while(j<=h)
    Help[k++]=a[j++];

    i=l;
    while(i<=h)
    {
        a[i]=Help[i];
        i++;
    }
   

}

void IterativeMergeSort(int a[], int n)
{
    int i,j,p;
    int l,m,h;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            m=(l+h)/2;

            Merge(a,l,m,h);
        }

        if(n-i>p/2)
        {
            l=i;
            h=i+p-1;
            m=(l+h)/2;
            Merge(a,l,m,n-1);
        }
    }

    if(p/2<n)
    {
        Merge(a,0,p/2-1,n-1);
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

    IterativeMergeSort(a,n);
    cout<<"\n\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }   
}