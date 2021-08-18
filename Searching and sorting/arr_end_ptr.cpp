#include<iostream>

using namespace std;

int main()
{
    int n=10;
    int i,j;
    int a[10]={2,5,8,9,6,3,1,4,7,0};

    int *p=a;

    cout<<*(p)<<"\n";
    cout<<*(p+1)<<"\n";
    cout<<*(p+2)<<"\n";
    cout<<*(p+n)<<"\n";
    cout<<*(p+n-1)<<"\n";

    
}