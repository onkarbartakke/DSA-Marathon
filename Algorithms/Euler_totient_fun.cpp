#include<iostream>

using namespace std;
const int N=1e5+2, MOD=1e9+7;

int totient[N];

int main()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        totient[i]=i;
    }

    for(i=2;i<N;i++)
    {
        if(totient[i]==i)
        {
            for(j=2*i;j<N;j=j+i)
            {
                totient[j]*=(i-1);
                totient[j]/=i; 
            } 

            totient[i]=i-1;  
        }
    }

    for(i=1;i<N;i++)
    {
        cout<<i<<" --> "<<totient[i]<<"\n";
    }
}