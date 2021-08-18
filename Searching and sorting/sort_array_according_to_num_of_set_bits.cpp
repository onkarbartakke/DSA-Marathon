#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int count_bits(int n)
{
    int count=0;

    while(n>0)
    {
        if(n&1)
        count++;

        n=n>>1;
    }

    return count;
}



void SortBy_setBits(int a[], int n)
{
    vector<vector<int>>V(n,vector<int>(2,0));

    int i,j;
    for(i=0;i<n;i++)
    {
        V[i][0]=count_bits(a[i]);
        V[i][1]=a[i];
    }

    sort(V.begin(),V.end());

    cout<<"\n\n";

    for(i=0;i<n;i++)
    {
        cout<<"Element : "<<V[i][1]<<"   SetBits : "<<V[i][0]<<"\n";
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


    SortBy_setBits(a,n);
}