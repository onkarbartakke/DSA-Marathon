#include<iostream>

using namespace std;

int Catlan(int n)
{
    int i,j;

    if(n==0)
    return 1;

    if(n==1)
    return 1;

    int cat[n+1];

    cat[0]=1;
    cat[1]=1;

    for(i=2;i<=n;i++)
    {
        cat[i]=0;
        for(j=0;j<i;j++)
        {
            cat[i]+=(cat[j]*cat[i-1-j]);
        }

        cout<<i<<" --> "<<cat[i]<<"\n";
    }

    return cat[n];
}

int main()
{
    int n,i;
    cout<<"Enter the val of N: ";
    cin>>n;

    cout<<Catlan(n);
}