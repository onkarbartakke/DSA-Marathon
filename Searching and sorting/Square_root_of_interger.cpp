#include<iostream>
#include<math.h>
using namespace std;

#define err 0.000001

double SquareRoot(int n)
{
    if(n==1)
    return 1.0;

    double l,h,mid;
    double ans=n/2;
    double a1,a2;
    a1=1;
    a2=n;

    while(abs(a1-a2)>err)
    {
        a1=(a1+a2)/2;
        a2=(n/a1);
    }

    return a1;

}

int main()
{
    int n;
    cout<<"Enter the num : ";
    cin>>n;
    cout<<"\nSquare root of "<<n<<" is : "<<SquareRoot(n);
}