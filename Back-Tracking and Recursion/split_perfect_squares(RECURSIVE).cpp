#include<iostream>

using namespace std;

int split_perfect_squares(int n)
{
    if(n<=3)
    {
        return n;
    }
    else
    {
        int ans=n;
        int i;
        for(i=1;i*i<=n;i++)
        {
            ans=min(ans, 1+split_perfect_squares(n-(i*i)));
        }

        return ans;
    }
}

int main()
{
    int n,i;
    cin>>n;
    int ans;
    ans=split_perfect_squares(n);
    cout<<"\n"<<ans;
}