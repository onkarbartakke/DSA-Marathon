#include<bits/stdc++.h>

using namespace std;

double multiply(double mid, int n)
{
    double ans = 1.0;

    for(int i=1;i<=n;i++)
    ans *= mid;

    return ans;
}

double Nth_root(int m, int n)
{
    double low = 1.0;
    double high = m;
    double eps = 1e-6;
    double mid;
    while(abs(high-low)>eps)
    {
        mid = (high+low)/2.0;

        if(multiply(mid,n) > m)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return low;
}
int main()
{
    int n,m;

    cout<<"Enter the number 'm' and root 'n' : ";
    cin>>m>>n;

    double r = Nth_root(m,n);

    cout<<"\n\n ANS : "<<r;
}