#include<iostream>

using namespace std;


int Kth_smallest(int *a1, int *a2, int *e1, int *e2, int k)
{
    if(a1==e1)
    return *(a1);

    if(a2==e2)
    return *(e2);

    int m1,m2;

    m1=((e1-a1+1)/2);
    m2=((e2-a2+1)/2);

    if(m1+m2<k)
    {
        if(a1[m1]>a2[m2])
        {
            return Kth_smallest(a1,a2+m2,e1,e2,k-m2-1);
        }
        else
        {
            return Kth_smallest(a1+m1,a2,e1,e2,k-m1-1);
        }
    }
    else
    {
        if(a1[m1]>a2[m2])
        {
            return Kth_smallest(a1,a2,e1-m1,e2,k);
        }
        else
        {
            return Kth_smallest(a1,a2,e1,e2-m2,k);
        }
    }
}
int main()
{
    int n,i,j,m;
    cout<<"Enter the size of 1st Array : ";
    cin>>n;
    cout<<"Enter the n elements in Sorted order : \n";
    int a1[n];
    for(i=0;i<n;i++)
    cin>>a1[i];

    cout<<"\nEnter the size of 2nd Array : ";
    cin>>m;
    int a2[m];
    cout<<"\nEnter the m elements in sorted order : \n";
    for(i=0;i<m;i++)
    cin>>a2[i];

    cout<<"\nEnter thr val of K , to find Kth smallest element : ";
    int k;
    cin>>k;
    int *e1,*e2;
    e1=a1+n-1;
    e2=a2+m-1;
    cout<<"\n**\n";
    cout<<"\nKth smallest Element is "<<Kth_smallest(a1,a2,e1,e2,k);


}